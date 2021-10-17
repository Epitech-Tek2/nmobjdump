/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** main
*/

#include <errno.h>
#include <string.h>
#include "../library/includes/assert.h"
#include "../library/utils/includes/index.h"
#include "nm.h"

static int arg_handling(register int const _ac,
    char const *restrict const *restrict _av, char **_binaries)
{
    register int n = 0;

    if (1 == _ac) {
        _binaries[0] = DEFAULT_BINARY;
        return (n);
    }
    for (register int i = 1; _av[i]; i++)
        if (_av[i][0] != '-') {
            _binaries[n] = (char *)_av[i];
            n++;
        }
    if (!n) _binaries[0] = DEFAULT_BINARY;
    return (n);
}

static int nm(register int const _ac, char const *restrict const *restrict _av)
{
    elf_t *elf = malloc(sizeof(elf_t));
    char **binaries = malloc(sizeof(char *) * (_ac + 1));
    int nbinary = 0;

    errno = 0;
    elf->sym = malloc(sizeof(sym_t));
    my_assert(elf, PROTO_DATA, ASSERT_INFO(strerror(errno),
        ERR_ALC84, FAIL_EXEC));
    my_assert(elf->sym, PROTO_DATA, ASSERT_INFO(strerror(errno),
        ERR_ALC84, FAIL_EXEC));
    nbinary = arg_handling(_ac, _av, binaries);
    for (int i = 0; binaries[i]; i++) {
        elf->bin.binpath = binaries[i];
        elf->bin.progname = _av[0];
        (void)((nbinary > 1) && printf("\n%s:\n", elf->bin.binpath));
        parse_binary(elf);
        elf_process(elf);
        write_sym(elf);
    }
    my_free(elf->sym, elf);
    return (1);
}

int main(int const ac, char const *restrict const *restrict av)
{
    return ((int)nm(ac, av) ? 0 : 84);
}
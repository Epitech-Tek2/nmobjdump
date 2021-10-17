/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** objdump
*/

#include <errno.h>
#include <string.h>
#include "../library/includes/assert.h"
#include "../library/utils/includes/index.h"
#include "objdump.h"

static int arg_handling(int _ac, char const *restrict const *restrict _av,
    elf_t *_elf, char **_binaries)
{
    if (1 == _ac) {
        _elf->flags[0] = "-f";
        _elf->flags[1] = "-s";
        _binaries[0] = my_strdup(DEFAULT_BINARY);
        _binaries[1] = NULL;
        return (3);
    }
    if (2 <= _ac) return (parsing_args_list(_av, _elf->flags, _binaries));
    return (1);
}

static void check_error_malloc(elf_t *_elf, char **_binaries)
{
    my_assert(_elf, PROTO_DATA, ASSERT_INFO(strerror(errno),
        ERR_ALC84, FAIL_EXEC));
    my_assert(_elf->flags, PROTO_DATA, ASSERT_INFO(strerror(errno),
        ERR_ALC84, FAIL_EXEC));
    my_assert(_binaries, PROTO_DATA, ASSERT_INFO(strerror(errno),
        ERR_ALC84, FAIL_EXEC));
}

static void exec_hander(elf_t *_elf, char **_binaries, int const _ac)
{
    for (int i = 0; _binaries[i]; i++) {
        _elf->bin.binpath = _binaries[i];
        if (4 == parse_binary(_elf)) break;
        (void)(find_in_tab("-a", _elf->flags) && write_archive(_elf, _ac));
        (void)(find_in_tab("-f", _elf->flags) && write_header(_elf));
        (void)(find_in_tab("-s", _elf->flags) && write_section(_elf));
    }
}

int objdump(int const _ac, char const *restrict const *restrict _av)
{
    elf_t *elf = malloc(sizeof(elf_t));
    char **binaries = malloc(sizeof(char *) * (_ac + 1));

    errno = 0;
    elf->flags = malloc(sizeof(char *) * (_ac + 1));
    check_error_malloc(elf, binaries);
    elf->bin.progname = _av[0];
    if (3 == arg_handling(_ac, _av, elf, binaries))
        exec_hander(elf, binaries, _ac);
    my_free(binaries, elf->flags, elf);
    return (1);
}
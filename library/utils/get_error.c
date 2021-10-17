/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** get_error
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../includes/objdump.h"
#include "includes/index.h"

void get_error(elf_t *_elf, char const *restrict _error)
{
    if (!my_strcmp(_elf->bin.binpath, "a.out"))
        fprintf(stderr, "%s: '%s': %s\n", _elf->bin.progname, _elf->bin.binpath
        , _error);
    else fprintf(stderr, "%s: %s: %s\n", _elf->bin.progname, _elf->bin.binpath,
        _error);
    free(_elf);
    exit(84);
}
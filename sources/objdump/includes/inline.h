/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** inline
*/

#pragma once

#include <stdnoreturn.h>
#include <features.h>

noreturn static __always_inline void ar_error(elf_t *_elf, ar_hdr_t *_ar,
    char const *restrict _error)
{
    free(_elf);
    free(_ar);
    printf("%s: '%s': %s\n", _elf->bin.progname, _elf->bin.binpath, _error);
    exit(84);
}
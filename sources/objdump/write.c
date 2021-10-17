/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** write
*/

#include "objdump.h"
#include "../library/utils/includes/index.h"

int write_archive(elf_t *_elf, register int const _ac)
{
    printf("\n%s:     file format elf64-x86-64\n%s%s",
        _elf->bin.binpath, _elf->bin.binpath, (2 == _ac || (3 <= _ac &&
        my_strcmp(_elf->bin.binpath, "a.out"))) ? "\n\n" : " ");
    return (1);
}
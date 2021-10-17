/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** inline
*/

#pragma once

#include <string.h>

static inline void is_wrong_st_info(elf_t *_elf, Elf64_Sym *tmp, int *i)
{
    if ((void *)&_elf->sym->strtab[tmp->st_name] > _elf->end)
        get_error(_elf, "Invalid file\n");
    if (!get_symbol_process(_elf, tmp, &_elf->sym->symbol[(*i)++]))
        get_error(_elf, "An error occured\n");
}

static inline int special_cmp(char const *a, char const *b)
{
    while (strchr("_@", *a) && (++a));
    while (strchr("_@", *b) && (++b));
    return (strcasecmp(a, b));
}
/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** struct
*/

#pragma once

typedef struct symbol_s
{
    uint32_t value;
    char type;
    char const *restrict name;
} symbol_t;

typedef struct type_s
{
    char c;
    uint32_t type;
    uint64_t flags;
} type_t;

typedef struct __attribute__((__packed__)) sym_s
{
    Elf64_Sym *start;
    Elf64_Sym *end;
    char *strtab;
    symbol_t *symbol;
} sym_t;
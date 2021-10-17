/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** index
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "./define.h"
#include "./struct.h"

int elf_process(elf_t *_elf);

int write_sym(elf_t *_elf);

int get_symbol_process(elf_t *_elf, Elf64_Sym *_sym, symbol_t *_symbol);

void sort_symbol(symbol_t *_sym);

#include "./inline.h"
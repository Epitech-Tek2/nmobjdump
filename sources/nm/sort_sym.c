/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** sort_sym
*/

#include <unistd.h>
#include <malloc.h>
#include "../library/utils/includes/index.h"
#include "nm.h"

static bool swap(symbol_t *const a, symbol_t *const b)
{
    symbol_t c;

    my_memcpy(&c, a, sizeof(c));
    my_memcpy(a, b, sizeof(c));
    my_memcpy(b, &c, sizeof(c));
    return (true);
}

static void process(symbol_t *_sym, int i)
{
    for (register int n = i - 1; nm_data_i_exist(n);)
        (void)((special_cmp(_sym[i].name, _sym[n].name) > 0) &&
            swap(&_sym[i], &_sym[n]));
}

void sort_symbol(symbol_t *_sym)
{
    for (register int i = -1; nm_data_i_exist(i);) process(_sym, i);
}
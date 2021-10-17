/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** main
*/

#include "../../includes/objdump.h"

int main(int const ac, char const *restrict const *restrict av)
{
    return (objdump(ac, av) ? 0 : 84);
}
/*
** EPITECH PROJECT, 2021
** library [WSL: Debian]
** File description:
** strlen
*/

#include "includes/index.h"
#include "../assert/includes/constant.h"
#include "../assert/includes/index.h"
#include <stdlib.h>
#include <stdbool.h>

size_t (my_strlen)(register char const *restrict string)
{
    int i = 0;

    if (!string) return (false);
    for (i = 0; string[i]; i++);
    return (i);
}
/*
** EPITECH PROJECT, 2021
** library [WSL: Debian]
** File description:
** macro
*/

#pragma once

#define _N__ARG(...) _N__ARGS(, ##__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define _N__ARGS(z, a, b, c, d, e, f, cnt, ...) cnt
/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** parsing_args
*/

#include "objdump.h"
#include "../library/utils/includes/index.h"

static void is_fusioned_flag(char **_flags, char const *restrict flag, int *n)
{
    if (!my_strcmp(flag, "-fs") || !my_strcmp(flag, "-sf")) {
        _flags[*n] = "-f";
        _flags[++(*n)] = "-s";
    } else if (!my_strcmp(flag, "-f") || !my_strcmp(flag, "-s") ||
        !my_strcmp(flag, "-a"))
        _flags[*n] = (char *)flag;
    else exit(84);
}

static void check_null_args(char **_flags, char **_binaries, int n, int x)
{
    if (0 == n) {
        _flags[0] = "-f";
        _flags[1] = "-s";
        _flags[2] = NULL;
    } else if (0 == x) {
        _binaries[0] = DEFAULT_BINARY;
        _binaries[1] = NULL;
    }
}

int parsing_args_list(char const *restrict const *restrict _av, char **_flags,
    char **_binaries)
{
    int n = 0;
    int x = 0;

    for (register int i = 1; _av[i]; i++) {
        if (_av[i][0] == '-') {
            is_fusioned_flag(_flags, _av[i], &n);
            n++;
        } else {
            _binaries[x] = (char *)_av[i];
            x++;
        }
    }
    _flags[n] = NULL;
    _binaries[x] = NULL;
    check_null_args(_flags, _binaries, n, x);
    return (3);
}
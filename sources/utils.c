/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** utils
*/

#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../library/includes/assert.h"
#include "../library/utils/includes/index.h"

int help(char const *restrict _filepath, int output)
{
    char *lineptr = NULL;
    size_t i = 500;
    FILE *stream = NULL;

    errno = 0;
    my_assert(_filepath, PROTO_DATA, ASSERT_INFO("Cannot read property " \
        "'_filepath' of undefined", ERR_TYPE, FAIL_EXEC));
    stream = fopen(_filepath, "r");
    my_assert(stream, PROTO_DATA, ASSERT_INFO(strerror(errno),
        ERR_TYPE, FAIL_EXEC));
    while (-1 != getline(&lineptr, &i, stream) && (printf("%s", lineptr)));
    free(lineptr);
    fclose(stream);
    exit(output);
}

void (my_free)(int _count, void *_ptr, ...)
{
    va_list list_ptr;

    free(_ptr);
    _ptr = NULL;
    for (va_start(list_ptr, _ptr); _count > 0; --_count)
        free(va_arg(list_ptr, void *));
    va_end(list_ptr);
}

void tprint(char **tab)
{
    for (int i = 0; tab[i]; i++)
        printf("%s\n", tab[i]);
}

bool find_in_tab(char const *restrict search, char **tab)
{
    for (int i = 0; tab[i]; i++)
        if (!my_strcmp(search, tab[i])) return (true);
    return (false);
}
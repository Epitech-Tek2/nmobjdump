/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** ar_file
*/

#include <errno.h>
#include <string.h>
#include "objdump.h"
#include "../../library/assert/includes/index.h"
#include "../../library/utils/includes/index.h"

int parse_ar_file(elf_t *_elf)
{
    ar_hdr_t *ar = NULL;

    errno = 0;
    if (!get_function_ar(_elf, &ar))
        get_error(_elf, "file format not recognized");
    get_header_ar(_elf, ar);
    if (!get_function_ar(_elf, &ar))
        get_error(_elf, "file format not recognized");
    printf("In archive %s:\n", _elf->bin.binpath);
    exec_function(_elf, ar);
    while (get_function_ar(_elf, &ar)) {
        exec_function(_elf, ar);
        my_free(_elf->ehdr, _elf->ar_file.name);
    }
    my_free(_elf->ar_file.header);
    return (4);
}
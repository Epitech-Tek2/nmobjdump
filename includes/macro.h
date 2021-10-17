/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** macro
*/

#pragma once

#define check_mmap(_elf, ptr) ({ \
    if ((void *)ptr > (void *)((char *)_elf->ehdr + _elf->ar_file.size)) \
        get_error(_elf, "File truncated"); \
})

#define IS_TRUNCATED _elf->ehdr->e_shoff + (_elf->ehdr->e_shentsize * \
    _elf->ehdr->e_shnum) != _elf->length

#define is_end_of_name(i) (_elf->ar_file.name[i] == '/')

#define _N__ARG(...) _N__ARGS(, ##__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define _N__ARGS(z, a, b, c, d, e, f, cnt, ...) cnt

#define free_ret(v, r) ({ \
    free(v); \
    return (r); \
})

#define my_free(ptr, ...) my_free(_N__ARG(__VA_ARGS__), ptr, ##__VA_ARGS__);
void (my_free)(int _count, void *_ptr, ...);
/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** getter
*/

#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/mman.h>
#include "struct.h"
#include "../library/assert/includes/index.h"
#include "../library/utils/includes/index.h"

bool get_function_ar(elf_t *_elf, ar_hdr_t **_ar)
{
    errno = 0;
    if (!*_ar) {
        *_ar = calloc(1, sizeof(ar_hdr_t) + 1);
        my_assert(*_ar, PROTO_DATA, ASSERT_INFO(strerror(errno),
            ERR_ALC84, FAIL_EXEC));
    }
    ((char *)*_ar)[sizeof(ar_hdr_t)] = 0;
    if (read(_elf->ar_file.fd, *_ar, sizeof(ar_hdr_t)) != sizeof(ar_hdr_t))
        free_ret(*_ar, false);
    ((char *)*_ar)[sizeof(ar_hdr_t)] = 0;
    if (memcmp((*_ar)->ar_fmag, ARFMAG, strlen(ARFMAG)))
        free_ret(*_ar, false);
    return (true);
}

void get_header_ar(elf_t *_elf, ar_hdr_t *_ar)
{
    errno = 0;
    _elf->ar_file.header_size = atoi(_ar->ar_size);
    _elf->ar_file.header = calloc(1, _elf->ar_file.header_size + 1);
    my_assert(_elf->ar_file.header, PROTO_DATA, ASSERT_INFO(strerror(errno),
        ERR_ALC84, FAIL_EXEC));
    my_assert((read(_elf->ar_file.fd, _elf->ar_file.header,
        _elf->ar_file.header_size)) == _elf->ar_file.header_size,
        PROTO_DATA, ASSERT_INFO(strerror(errno), ERR_ALC84, FAIL_EXEC));
    _elf->ar_file.header[_elf->ar_file.header_size] = '\0';
}

static void get_function_name(elf_t *_elf)
{
    register int size = 0;

    if (is_end_of_name(0)) {
        size = atoi(&_elf->ar_file.name[1]);
        if (size < _elf->ar_file.header_size)
            _elf->ar_file.name = &_elf->ar_file.header[size];
    }
    _elf->ar_file.name = strndup(_elf->ar_file.name,
        strcspn(_elf->ar_file.name, "/"));
}

static void get_function_ehdr(elf_t *_elf)
{
    if (_elf->ar_file.size < (int)sizeof(Elf64_Ehdr))
        get_error(_elf, "File format not recognized");
    _elf->ehdr = malloc(_elf->ar_file.size + 1);
    read(_elf->ar_file.fd, _elf->ehdr, _elf->ar_file.size);
    ((char *)_elf->ehdr)[_elf->ar_file.size] = 0;
    if (memcmp(_elf->ehdr->e_ident, ELFMAG, strlen(ELFMAG)))
        get_error(_elf, "File format not recognized");
}

bool exec_function(elf_t *_elf, ar_hdr_t *_ar)
{
    _elf->ar_file.size = my_atoi(_ar->ar_size);
    _elf->ar_file.name = _ar->ar_name;
    get_function_name(_elf);
    _elf->bin.binpath = _elf->ar_file.name;
    get_function_ehdr(_elf);
    _elf->shdr = (Elf64_Shdr *)((char *)_elf->ehdr + _elf->ehdr->e_shoff);
    check_mmap(_elf, _elf->shdr + 1);
    check_mmap(_elf, OFFSET_SECTION_HEADER);
    check_mmap(_elf, &(_elf->shdr[_elf->ehdr->e_shnum]));
    (void)(find_in_tab("-f", _elf->flags) && write_header(_elf));
    (void)(find_in_tab("-s", _elf->flags) && write_section(_elf));
    return (true);
}
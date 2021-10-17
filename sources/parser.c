/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** test
*/

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include "../library/includes/assert.h"
#include "../library/utils/includes/index.h"

int check_binary(elf_t *_elf)
{
    if (memcmp(_elf->ehdr, MAGIC, SIZE_MAGIC - 1) || _elf->length < SIZE_EHDR)
        get_error(_elf, "file format not recognized");
    if (IS_TRUNCATED) get_error(_elf, "file format not recognized");
    _elf->shdr = (Elf64_Shdr *)((char *)_elf->ehdr + _elf->ehdr->e_shoff);
    if ((void *)_elf->shdr > _elf->end || (void *)&SHDR_SHSTRNDX > _elf->end ||
        (void *)_elf->ehdr + SHDR_SHSTRNDX.sh_offset > (void *)_elf->end)
            get_error(_elf, "invalid file");
    return (1);
}

static bool check_type_binary(elf_t *_elf)
{
    char magic_ar[SARMAG];

    _elf->ar_file.fd = open(_elf->bin.binpath, O_RDONLY);
    my_assert(_elf->ar_file.fd != 1, PROTO_DATA, ASSERT_INFO(strerror(errno),
        EXEC_ERR, FAIL_EXEC));
    return (read(_elf->ar_file.fd, magic_ar, SARMAG) != SARMAG ||
        strncmp(magic_ar, ARMAG, SARMAG)) ? (false) : (true);
}

int parse_binary(elf_t *_elf)
{
    int fd = 0;

    errno = 0;
    if (check_type_binary(_elf)) return (parse_ar_file(_elf));
    close(_elf->ar_file.fd);
    fd = open(_elf->bin.binpath, O_RDONLY);
    my_assert(fd != 1, PROTO_DATA, ASSERT_INFO(strerror(errno),
        EXEC_ERR, FAIL_EXEC));
    _elf->length = lseek(fd, 0, SEEK_END);
    if (fd == -1) get_error(_elf, "No such file");
    _elf->ehdr = mmap(NULL, _elf->length, PROT_READ, MAP_SHARED, fd, 0);
    my_assert(_elf->ehdr != MAP_FAILED, PROTO_DATA,
        ASSERT_INFO(strerror(errno), EXEC_ERR, FAIL_EXEC));
    _elf->end = (Elf64_Shdr *)_elf->ehdr + _elf->length;
    return (check_binary(_elf));
}
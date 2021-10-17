/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** write
*/

#include "objdump.h"
#include "../library/includes/assert.h"
#include "../library/utils/includes/index.h"

uint32_t get_flag(elf_t *_elf)
{
    uint32_t flags = 0;
    int symFlag = 0;

    flags |= (_elf->ehdr->e_type == ET_REL) ? HAS_RELOC :
        (_elf->ehdr->e_type == ET_EXEC) ? EXEC_P : 0;
    for (int i = 0; i < _elf->ehdr->e_shnum; i++) {
        if (_elf->shdr[i].sh_type != SHT_SYMTAB ||
            _elf->shdr[i].sh_type != SHT_DYNAMIC)
            symFlag = 1;
    }
    if (symFlag == 1) flags |= HAS_SYMS;
    if (_elf->ehdr->e_type == ET_DYN) flags |= DYNAMIC;
    if (_elf->ehdr->e_phnum != 0) flags |= D_PAGED;
    return (flags);
}

static flag_t const flags_type[] = {
    {HAS_RELOC, "HAS_RELOC"},
    {EXEC_P, "EXEC_P"},
    {HAS_LINENO, "HAS_LINENO"},
    {HAS_DEBUG, "HAS_DEBUG"},
    {HAS_SYMS, "HAS_SYMS"},
    {HAS_LOCALS, "HAS_LOCALS"},
    {DYNAMIC, "DYNAMIC"},
    {WP_TEXT, "WP_TEXT"},
    {D_PAGED, "D_PAGED"},
    {BFD_IS_RELAXABLE, "BFD_IS_RELAXABLE"},
    {HAS_LOAD_PAGE, "HAS_LOAD_PAGE"}
};

static void display_flags(uint32_t flags)
{
    char *str = "";

    for (int i = 0; i < (int)(sizeof(flags_type) / sizeof(*flags_type)); i++) {
        if (flags & flags_type[i].id) {
            printf("%s%s", str, flags_type[i].value);
            str = ", ";
        }
    }
}

int write_header(elf_t *_elf)
{
    uint32_t flags = 0;

    if (_elf->ehdr->e_type == ET_EXEC) flags = 274;
    else if (_elf->ehdr->e_type == ET_DYN) flags = 336;
    else if (_elf->ehdr->e_type == ET_REL) flags = 17;
    printf("\n%s:     file format %s\n", _elf->bin.binpath, "elf64-x86-64");
    printf("architecture: i386:x86-64, flags 0x%08x:\n", get_flag(_elf));
    display_flags(flags);
    printf("\nstart address 0x%016lx\n\n", _elf->ehdr->e_entry);
    return (0);
}
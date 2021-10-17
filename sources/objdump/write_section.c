/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** write_section
*/

#include "objdump.h"
#include "../library/includes/assert.h"
#include "../library/utils/includes/index.h"

static char const *restrict unless_section[] = {
    "",
    ".bss",
    ".shstrtab",
    ".symtab",
    ".strtab",
    ".rela.text",
    ".rela.debug_info",
    ".rela.debug_aranges",
    ".rela.debug_line",
    ".rela.eh_frame",
    ".tbss",
    "__libc_freeres_ptrs",
    NULL
};

static int is_unless_section(elf_t *_elf, int section)
{
    if (!_elf->shdr[section].sh_size) return (true);
    for (int i = 0; unless_section[i] != NULL; i++) {
        if (!my_strcmp(unless_section[i],
            &OFFSET_SECTION_HEADER[_elf->shdr[section].sh_name]))
            return (true);
    }
    return (false);
}

static void print_values(uint8_t *data, int size)
{
    for (int i = 0; i < 16; i++) {
        if (i < size) printf("%02x", data[i]);
        else printf("  ");
        if (0 == (i + 1) % 4) printf(" ");
    }
    printf(" ");
    for (int i = 0; i < 16; i++)
        if (i < size) printf("%c", (data[i] >= 32 && data[i] <= 126) ?
            data[i] : '.');
        else printf(" ");
}

static void print_content(elf_t *_elf, int _i)
{
    for (unsigned int n = _elf->shdr[_i].sh_offset; n <
        (unsigned int)(_elf->shdr[_i].sh_offset + _elf->shdr[_i].sh_size);
        n += (1 << 4)) {
        printf(" %04x ", (int)(_elf->shdr[_i].sh_addr + n -
            _elf->shdr[_i].sh_offset));
        print_values((unsigned char *)_elf->ehdr + n, _elf->shdr[_i].sh_offset
            + _elf->shdr[_i].sh_size - n);
        printf("\n");
    }
}

int write_section(elf_t *_elf)
{
    if (!find_in_tab("-f", _elf->flags))
        printf("\n%s:     file format %s\n\n", _elf->bin.binpath,
            "elf64-x86-64");
    for (int i = 0; i < _elf->ehdr->e_shnum; i++) {
        if (is_unless_section(_elf, i)) continue;
        printf("Contents of section %s:\n",
            &OFFSET_SECTION_HEADER[_elf->shdr[i].sh_name]);
        print_content(_elf, i);
    }
    return (1);
}
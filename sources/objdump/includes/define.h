/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** define
*/

#pragma once

#include <elf.h>

#define DEFAULT_BINARY "a.out"

#define MAGIC "\177ELF"
#define SIZE_MAGIC sizeof("\177ELF")

#define SIZE_EHDR sizeof(Elf64_Ehdr)

#define exit_help(filepath) ({ \
    help(filepath); \
    exit(84); \
})

#define SHDR_SHSTRNDX _elf->shdr[_elf->ehdr->e_shstrndx]

#define LENGTH_SECTION (unsigned int)(_elf->shdr->sh_offset + \
    _elf->shdr->sh_size)

#define SECTION_LINE_ADDR _elf->shdr->sh_addr + i - _elf->shdr->sh_offset

/* Offset pointing to the section table in the header */
#define OFFSET_SECTION_HEADER ((char *)_elf->ehdr + SHDR_SHSTRNDX.sh_offset)
/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** elf_process
*/

#include "../library/includes/assert.h"
#include "../library/utils/includes/index.h"
#include "nm.h"

static void check_invalid(elf_t *_elf)
{
    if ((void *)_elf->sym->start > _elf->end ||
        (void *)_elf->sym->end > _elf->end ||
        (void *)_elf->sym->strtab > _elf->end)
        get_error(_elf, "Invalid file\n");
}

int elf_process(elf_t *_elf)
{
    for (int i = 0; i != _elf->ehdr->e_shnum; i++)
        if (_elf->shdr[i].sh_type == SHT_SYMTAB) {
            _elf->sym->start = SYM_START;
            _elf->sym->end = SYM_END;
            _elf->sym->strtab = SYM_STR;
            check_invalid(_elf);
        }
    if ((_elf->sym->end < _elf->sym->start) ||
        (!_elf->sym->end || !_elf->sym->start))
        get_error(_elf, "No symbols\n");
    return (1);
}
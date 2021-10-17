/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** define
*/

#pragma once

#define SIZEOF_SYMBOL_STRUCT (sizeof(symbol_t) * \
    (_elf->sym->end - _elf->sym->start))

#define NM_TYPE_NAME _elf->sym->symbol[i].type, _elf->sym->symbol[i].name

#define NM_DATA _elf->sym->symbol[i].value, NM_TYPE_NAME

#define NM_DATA_EXIST _elf->sym->symbol[i].value || \
    _elf->sym->symbol[i].type || _elf->sym->symbol[i].name

#define nm_data_i_exist(i) _sym[++i].value || _sym[i].type || _sym[i].name

#define TYPE_BRANCH _elf->sym->symbol[i].value != 0 || \
    _elf->sym->symbol[i].type == 't' || _elf->sym->symbol[i].type == 'n' || \
    _elf->sym->symbol[i].type == 'T'

#define TYPE_UNDEFINED _elf->sym->symbol[i].type == 'w' || \
    _elf->sym->symbol[i].type == 'U'

#define IS_WRONG_ST_INFO tmp->st_info != STT_FILE && \
    tmp->st_info != STT_SECTION && tmp->st_info != STT_NOTYPE

#define SYM_START (Elf64_Sym *)((void *)_elf->ehdr + _elf->shdr[i].sh_offset)
#define SYM_STR \
    (char *)_elf->ehdr + _elf->shdr[_elf->shdr[i].sh_link].sh_offset
#define SYM_END (Elf64_Sym *)((void *)_elf->sym->start + _elf->shdr[i].sh_size)
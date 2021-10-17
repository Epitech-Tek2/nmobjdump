/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** write_sym
*/

#include <errno.h>
#include <string.h>
#include "../library/includes/assert.h"
#include "../library/utils/includes/index.h"
#include "nm.h"

static type_t const types[] =
{
    {'B', SHT_NOBITS, SHF_ALLOC | SHF_WRITE},
    {'R', SHT_PROGBITS, SHF_ALLOC},
    {'D', SHT_PROGBITS, SHF_ALLOC | SHF_WRITE},
    {'U', SHT_NULL, 0},
    {'T', SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR},
    {'R', SHT_PROGBITS, 0}
};

static char get_type(elf_t *_elf, Elf64_Sym *_sym)
{
    if (_sym->st_shndx == SHN_UNDEF) return ('U');
    if (_sym->st_shndx == SHN_COMMON) return ('C');
    if (_sym->st_shndx == SHN_ABS) return ('A');
    for (register uint64_t i = 0; (unsigned)i <
        (sizeof(types) / sizeof(*types)); i++) {
        if ((void *)&_elf->shdr[_sym->st_shndx] > _elf->end)
            get_error(_elf, "Invalid file\n");
        if (_elf->shdr[_sym->st_shndx].sh_type == types[i].type &&
            _elf->shdr[_sym->st_shndx].sh_flags == types[i].flags)
            return (types[i].c);
    }
    return ('?');
}

int get_symbol_process(elf_t *_elf, Elf64_Sym *_sym, symbol_t *_symbol)
{
    _symbol->value = (uint32_t)_sym->st_value;
    _symbol->type = get_type(_elf, _sym);
    if (ELF64_ST_BIND(_sym->st_info) == STB_LOCAL)
        _symbol->type = (_symbol->type >= 'A' && _symbol->type <= 'Z' ?
            _symbol->type + 0x20 : _symbol->type);
    if (ELF64_ST_BIND(_sym->st_info) == STB_WEAK) _symbol->type = 'w';
    _symbol->name = &_elf->sym->strtab[_sym->st_name];
    return (1);
}

static void get_symbol(elf_t *_elf)
{
    Elf64_Sym *tmp = NULL;

    _elf->sym->symbol = malloc(SIZEOF_SYMBOL_STRUCT);
    my_assert(_elf->sym->symbol, PROTO_DATA, ASSERT_INFO(strerror(errno),
        ERR_ALC84, FAIL_EXEC));
    my_memset(_elf->sym->symbol, 0, SIZEOF_SYMBOL_STRUCT);
    tmp = _elf->sym->start;
    for (int i = 0; tmp < _elf->sym->end; tmp++)
        if (IS_WRONG_ST_INFO) is_wrong_st_info(_elf, tmp, &i);
}

int write_sym(elf_t *_elf)
{
    get_symbol(_elf);
    sort_symbol(_elf->sym->symbol);
    for (register int i = 0; NM_DATA_EXIST; i++) {
        if (TYPE_UNDEFINED)
            printf("%18c %s\n", _elf->sym->symbol[i].type,
                _elf->sym->symbol[i].name);
        else if (TYPE_BRANCH)
            printf("%016x %c %s\n", _elf->sym->symbol[i].value,
            _elf->sym->symbol[i].type, _elf->sym->symbol[i].name);
    }
    return (1);
}
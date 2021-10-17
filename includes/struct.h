/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** struct
*/

#pragma once

#include <elf.h>
#include <ar.h>
#include <stdlib.h>
#include <stdio.h>
#include "../sources/nm/includes/struct.h"

typedef struct bin_s
{
    char const *restrict progname;
    char const *restrict binpath;
    char const *restrict flag;
} bin_t;

typedef struct ar_file_s
{
    int fd;
    char *name;
    size_t size;
    char *header;
    int header_size;
} ar_file_t;

typedef struct __attribute__((__packed__)) elf_s
{
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    ar_file_t ar_file;
    void *end;
    char **flags;
    sym_t *sym;
    bin_t bin;
    size_t length;
    int nglags;
    char *strtab;
} elf_t;

typedef struct flag_s
{
    int const id : 13;
    char const *restrict value;
} flag_t;

typedef struct ar_hdr ar_hdr_t;
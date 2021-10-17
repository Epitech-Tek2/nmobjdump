/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** index
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "./define.h"

/**
 * @brief Writes the binary header
 *
 * @param _elf (elf_t *elf) structure.
 * @return (int) - exit(84) if an error occured.
 */
int write_header(elf_t *_elf);

/**
 * @brief Writes the binary sections
 *
 * @param _elf (elf_t *elf) structure.
 * @return (int) - exit(84) if an error occured.
 */
int write_section(elf_t *_elf);

/**
 * @brief If any of the objfile files are archives, display the archive header
 * information (in a format similar to ‘ls -l’). Besides the information you
 * could list with ‘ar tv’, ‘objdump -a’ shows the object file format of each
 * archive member.
 *
 * @param _elf (elf_t *elf) structure.
 * @return (int) - exit(84) if an error occured.
 */
int write_archive(elf_t *_elf, register int const _ac);

int objdump(int const _ac, char const *restrict const *restrict _av);

int parsing_args_list(char const *restrict const *restrict _av, char **_flags,
    char **_binaries);

void tprint(char **tab);

bool find_in_tab(char const *restrict search, char **tab);

int parse_ar_file(elf_t *_elf);
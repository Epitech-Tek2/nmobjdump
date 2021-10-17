/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** func
*/

#pragma once

#include <stdbool.h>

/**
 * @brief Prints help description.
 *
 * @param _filepath filepath to the help text.
 * @return (int)
 */
int help(char const *restrict _filepath, int output);

/**
 * @brief Parses the binary and create the elf structur.
 *
 * @param _elf (elf_t *elf) structure.
 * @return (int) - exit(84) if an error occured.
 */
int parse_binary(elf_t *_elf);

int check_binary(elf_t *_elf);

bool get_function_ar(elf_t *_elf, ar_hdr_t **_ar);
void get_header_ar(elf_t *_elf, ar_hdr_t *_ar);
bool exec_function(elf_t *_elf, ar_hdr_t *_ar);
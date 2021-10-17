/*
** EPITECH PROJECT, 2021
** library [WSL: Debian]
** File description:
** index
*/

#pragma once

#include <setjmp.h>
#include <stdio.h>
#include "../../includes/macro.h"
#include "../../includes/struct.h"
#include "constant.h"
#include "macro.h"

/**
 * Evaluates expression and my_assert error if it false
 * @param expr Expression to evaluate.
 * @param infos PROTO_DATA
 * @param assert_data ASSERT_INFO(DESC_ERR_TOO_MANY_ARGUMENT, EXEC_ERR,
 * FAIL_EXEC)
 */
#define my_assert(expr, infos, assert_data) (expr) ? (1) : \
my_assert(#expr, infos, assert_data)

/* Evalue the expr and abort if it's true */
int (my_assert)(char const *assertion, global_info_t infos, \
    assert_info_t assert_data);

/**
 * Evaluates expression and my_assert warning if it false
 * @param expr Expression to evaluate.
 * @param DESC_WARN_XXX_FAILED description of warning.
 * @param WARN_XXX Num of warning.
 * @param FAIL_XXX Type of error.
 */
#define my_warning_assert(expr, infos, assert_data, jmp) (expr) ? (1) : \
my_warning_assert(#expr, infos, assert_data, jmp)

/* Evalue the expr and print warning if it's true */
int (my_warning_assert)(char const *assertion,
    global_info_t infos, assert_info_t assert_data);
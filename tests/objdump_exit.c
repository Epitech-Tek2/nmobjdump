/*
** EPITECH PROJECT, 2021
** nmobjdump [WSL: Ubuntu]
** File description:
** objdump
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "objdump.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_objdump, no_such_file, .exit_code = 84)
{
    char *args[3];

    args[0] = "./my_objdump";
    args[1] = "test";
    args[2] = NULL;
    objdump(3, (char const *const *)args);
}

Test(my_objdump, no_such_file_with_flag, .exit_code = 84)
{
    char *args[4];

    args[0] = "./my_objdump";
    args[1] = "zf";
    args[2] = "-s";
    args[3] = NULL;

    objdump(3, (char const *const *)args);
}

Test(my_objdump, file_not_found, .exit_code = 84)
{
    char *args[4];

    args[0] = "./my_objdump";
    args[1] = "-s";
    args[2] = "test";
    args[3] = NULL;

    objdump(3, (char const *const *)args);
}

Test(my_objdump, correct_call_bin, .exit_code = 0)
{
    char *args[4];

    args[0] = "./my_objdump";
    args[1] = "-fs";
    args[2] = "tests/bin/my_nm";
    args[3] = NULL;
    objdump(3, (char *const *const)args);
}

Test(my_objdump, correct_call_lib, .exit_code = 0)
{
    char *args[4];

    args[0] = "./my_objdump";
    args[1] = "-fs";
    args[2] = "tests/bin/libutils.a";
    args[3] = NULL;
    objdump(3, (char *const *const)args);
}
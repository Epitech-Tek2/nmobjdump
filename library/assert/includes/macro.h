/*
** EPITECH PROJECT, 2021
** clibrary
** File description:
** macro
*/

#pragma once

#include "../../includes/struct.h"

#define PROTO_DATA (struct global_info_s) \
    {.file = __FILE__, .line = __LINE__, .time = __TIME__ , .func = __func__}

#define ASSERT_INFO(desc, type, nbr) (struct assert_info_s){desc, type, nbr}
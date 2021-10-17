/*
** EPITECH PROJECT, 2021
** library [WSL: Debian]
** File description:
** struct
*/

#pragma once

#include <stdbool.h>

typedef enum type { STRING, NUMBER, ARRAY_STRING, ARRAY_NUMBER } type;

typedef struct vect2i_s
{
    int x;
    int y;
} vect2i;

typedef struct vect3i_s
{
    int x;
    int y;
    int z;
} vect3i;

typedef struct global_info_s
{
    char *file;
    char *time;
    const char *func;
    int line;
} global_info_t;

typedef struct assert_info_s
{
    char *desc;
    char *type;
    char *nbr;
} assert_info_t;
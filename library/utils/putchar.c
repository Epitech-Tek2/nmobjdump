/*
** EPITECH PROJECT, 2021
** library [WSL: Debian]
** File description:
** print
*/

#include <unistd.h>

void my_putchar(char character, int fd)
{
    write(fd, &character, 1);
}
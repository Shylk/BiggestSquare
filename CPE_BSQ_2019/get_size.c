/*
** EPITECH PROJECT, 2019
** second part of step 4
** File description:
** oui
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <fcntl.h>
#include <unistd.h>

int get_nb_rows(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[20000];
    int size = read(fd, buffer, 19999);
    char *result = malloc(sizeof(char) * 50);
    int cols = 0;
    int i = 0;

    for (i; buffer[i] != '\n'; i++)
        result[i] = buffer[i];
    cols = my_getnbr(result);
    close (fd);
    return (cols);
}

int get_nb_cols(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[20000];
    int size= read(fd, buffer, 19999);
    int i = 0;
    char *result = malloc(sizeof(char) * 50);
    int cols = 0;

    for (i; buffer[i] != '\n'; i++);
    i++;
    for (i; buffer[i] != '\n'; i++) {
        cols++;
    }
    close (fd);
    return (cols);
}

int get_square_row(int **map, int nb_rows, int nb_cols, int max_value)
{
    int col = 0;
    int square_row = 0;
    int square_col = 0;

    for (int row = 0; row < nb_rows; row++) {
        for (col; col < nb_cols; col++) {
            if (map[row][col] == max_value) {
                square_row = row;
                return (square_row);
            }
        }
        col = 0;
    }
}

int get_square_col(int **map, int nb_rows, int nb_cols, int max_value)
{
    int col = 0;
    int square_row = 0;
    int square_col = 0;

    for (int row = 0; row < nb_rows; row++) {
        for (col; col < nb_cols; col++) {
            if (map[row][col] == max_value) {
                square_col = col;
                return (square_col);
            }
        }
        col = 0;
    }
}

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int i = 0;
    int j = 0;
    int row_count = row;
    int col_count = col;

    for (i; row < (row_count + square_size); row++) {
        for (j; col < (col_count + square_size); col++) {
            if (map[row][col] != '.')
                return (0);
            i++;
        }
        col = col_count;
    }
    if (i == square_size * square_size)
        return (1);
    return (-1);
}

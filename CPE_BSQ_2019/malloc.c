/*
** EPITECH PROJECT, 2019
** malloc
** File description:
** malloc 2d array for main function
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr = malloc(sizeof(char *) * (nb_rows + 4));

    for (int rows = 0; rows < nb_rows + 4; rows++) {
        arr[rows] = malloc(sizeof(char) * (nb_cols + 1));
    }
    return (arr);
}

int **mem_alloc_2d_int_array(int nb_rows, int nb_cols)
{
    int **arr = malloc(sizeof(char *) * (nb_rows + 1));

    for (int rows = 0; rows < nb_rows; rows++) {
        arr[rows] = malloc(sizeof(char) * (nb_cols + 1));
    }
    return (arr);
}

void free_main_char(char **arr, int nb_rows, int nb_cols)
{
    for (int rows = 0; rows < nb_rows; rows++) {
        free(arr[rows]);
    }
}

void free_main_int(int **arr_num, int nb_rows, int nb_cols)
{
    for (int rows = 0; rows < nb_rows; rows++) {
        free(arr_num[rows]);
    }
}

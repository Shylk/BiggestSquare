/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find the Biggest SQuare out of a map filled by . and o
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int return_the_lowest_case(int **map, int row, int col)
{
    int upper_left_is_bigger = 0;
    int up_left = map[row - 1][col - 1];
    int up = map[row - 1][col];
    int left = map[row][col - 1];

    if (up_left >= up)
        upper_left_is_bigger = 1;
    if (upper_left_is_bigger == 1) {
        if (up >= left)
            return (left);
        else
            return (up);
    }
    if (upper_left_is_bigger == 0) {
        if (up_left >= left)
            return (left);
        else
            return (up_left);
    }
}

int get_the_biggest_value(int **map, int nb_rows, int nb_cols)
{
    int temp = 0;
    int max_value = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < nb_rows; i++) {
        for (j; j < nb_cols; j++) {
            temp = map[i][j];
            if (temp >= max_value)
                max_value = temp;
        }
        j = 0;
    }
    return (max_value);
}

void write_x(char **array, int max_value, int square_row, int square_col)
{
    int stock_col = square_col;
    int j = 0;

    for (int i = 0; i < max_value; i++, square_row--) {
        for (j; j < max_value; j++, square_col--) {
            array[square_row][square_col] = 'x';
        }
        j = 0;
        square_col = stock_col;
    }
}

int find_biggest_square(int **map, char **array, int nb_rows, int nb_cols)
{
    int col = 1;
    int max_value = 0;
    int square_row = 0;
    int square_col = 0;

    for (int row = 1; row < nb_rows; row++) {
        for (col; col < nb_cols; col++) {
            if (map[row][col] == 0);
            else
                map[row][col] = return_the_lowest_case(map, row, col) + 1;
        }
        col = 1;
    }
    max_value = get_the_biggest_value(map, nb_rows, nb_cols);
    square_row = get_square_row(map, nb_rows, nb_cols, max_value);
    square_col = get_square_col(map, nb_rows, nb_cols, max_value);
    write_x(array, max_value, square_row, square_col);
    for (int row = 0; row < nb_rows; row++) {
        my_putstr(array[row]);
    }
}

int main(int argc, char **argv)
{
    int check = 0;
    int check2 = 0;
    check = error_handling(argv[1]);
    check2 = read_nothing(argv[1]);
    if (check == 1 || check2 == 1)
        return (84);
    int nb_rows = get_nb_rows(argv[1]);
    int nb_cols = get_nb_cols(argv[1]);
    char **arr = mem_alloc_2d_array(nb_rows, nb_cols);
    int **arr_num = mem_alloc_2d_int_array(nb_rows, nb_cols);

    arr = load_2d_arr_from_file(argv[1], nb_rows, nb_cols);
    arr_num = mem_dup_2d_array(arr, nb_rows, nb_cols);
    find_biggest_square(arr_num, arr, nb_rows, nb_cols);
    free_main_char(arr, nb_rows, nb_cols);
    free_main_int(arr_num, nb_rows, nb_cols);
    return (0);
}

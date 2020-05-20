/*
** EPITECH PROJECT, 2019
** load
** File description:
** put the files into a 2d array
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    stat(filepath, &st);
    int bytes = st.st_size;
    char buffer[bytes + 110000];
    int size = read(fd, buffer, (bytes + 110000));
    char **loaded_file = mem_alloc_2d_array(nb_rows, nb_cols);
    int j = 0;
    int k = 0;
    for (k; buffer[k] != '\n'; k++);
    k++;
    for (int i = 0; buffer[k] != '\0'; i++, k++) {
        for (j; buffer[k] != '\n'; k++, j++) {
            loaded_file[i][j] = buffer[k];
            if (buffer[k + 1] == '\n')
                loaded_file[i][j + 1] = '\n';
        }
        j = 0;
    }
    close(fd);
    return (loaded_file);
}

int **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    int **array = malloc(nb_rows * sizeof(int *));

    for (int rows = 0; rows < nb_rows; rows++) {
        array[rows] = malloc(nb_cols * sizeof(int));
        for (int cols = 0; cols < nb_cols; cols++) {
            if (arr[rows][cols] == 'o')
                array[rows][cols] = 0;
            if (arr[rows][cols] == '.')
                array[rows][cols] = 1;
        }
    }
    return (array);
}

int error_handling(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    close(fd);
    if (fd == -1)
        return (1);
    return (0);
}

int read_nothing(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[110000];
    int size = read(fd, buff, 110000);

    close(fd);
    if (size == 0)
        return (1);
    return (0);
}

/*
** EPITECH PROJECT, 2019
** int to str
** File description:
** int to array
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

char *my_int_to_str(int to_array)
{
    char *result;
    int nbr = 0;
    int count = 0;
    int temp = to_array;
    int i = 0;
    int j = 0;

    if (to_array < 0) {
        to_array = -to_array;
        count = 1;
    } result = malloc(sizeof(char) * (j + 1));
    for (i; to_array / 10 != 0; i++) {
        nbr = to_array % 10;
        result[i] = nbr + '0';
        to_array /= 10;
    } result[i] = to_array + '0';
    result[i + 1] = '\0';
    if (count == 1)
        result[i + 1] = '-';
    result = my_revstr(result);
    return (result);
}

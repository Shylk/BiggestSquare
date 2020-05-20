/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

int my_evil_length(char *str)
{
    int i = 0;
    int max_length = 0;

    for (i = 0; str[i] != '\0'; i++) {
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_evil_length(str);
    char *temp;
    len = len - 1;

    while (len > i) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i = i + 1;
        len = len - 1;
    }
    return (str);
}

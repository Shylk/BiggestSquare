/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copies a string into another
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int max_length = my_strlen(src);
    int i = 0;

    for (i; i < max_length; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

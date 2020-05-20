/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display the number given as a parameter
*/

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 10 != 0) {
        my_put_nbr( nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

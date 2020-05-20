/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** return n^p
*/

int my_compute_power_rec(int nb, int p)
{
    int i = 1;
    int total = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    total = nb * my_compute_power_rec(nb, p -1);
    return (total);
}

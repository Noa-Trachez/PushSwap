/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-pushswap-noa.trachez
** File description:
** sorting.c
*/

#include "pushswap.h"

long long power_nbr(long long power)
{
    long long nbr = 1;
    for (long long i = 1; i < power; i++)
        nbr *= 10;
    return (nbr);
}

long len_nbr(long max)
{
    long len_max = 0;

    for (; max > 0; len_max++)
        max /= 10;
    return (len_max);
}

void continue_algo_sort(linked_list_t **l_a, linked_list_t **l_b,
long long *nbr, char *output)
{
    long ten = power_nbr(nbr[1]);

    if ((*l_a) && (*l_a)->data % ten / (ten / 10) == nbr[0]) {
        allpop(l_a, l_b);
        my_strcpy(output + nbr[2], "pb ");
        nbr[2] += 3;
    } else {
        rotation(l_a);
        my_strcpy(output + nbr[2], "ra ");
        nbr[2] += 3;
    }
}

void algo_sort(linked_list_t **l_a, linked_list_t **l_b,
long long *nbr, char *output)
{
    linked_list_t *last_la;
    long ten = power_nbr(nbr[1]);

    if ((*l_a))
        last_la = (*l_a)->previous;
    else
        last_la = NULL;
    while ((*l_a) != last_la) {
        if ((*l_a)->data % ten / (ten / 10) == nbr[0]) {
            allpop(l_a, l_b);
            my_strcpy(output + nbr[2], "pb ");
            nbr[2] += 3;
        } else {
            rotation(l_a);
            my_strcpy(output + nbr[2], "ra ");
            nbr[2] += 3;
        }
    }
    continue_algo_sort(l_a, l_b, nbr, output);
}

void sort_linked_list(linked_list_t **l_a, linked_list_t **l_b,
long max, char *output)
{
    long len_max = len_nbr(max);
    long long nbr[3];

    nbr[2] = 0;
    for (int power = 2; power <= len_max + 1; power++) {
        nbr[1] = power;
        for (int modulo = 0; modulo < 10; modulo++) {
            nbr[0] = modulo;
            algo_sort(l_a, l_b, nbr, output);
        }
        while ((*l_b)) {
            allpop(l_b, l_a);
            my_strcpy(output + nbr[2], "pa ");
            nbr[2] += 3;
        }
    }
    write(1, output, nbr[2] - 1);
    write(1, "\n", 1);
}

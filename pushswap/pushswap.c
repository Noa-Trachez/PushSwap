/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-pushswap-noa.trachez
** File description:
** linked_list.c
*/

#include "pushswap.h"

int error_base(int ac, char **argv)
{
    if (ac == 1) {
        write(2, "Too few arguments\n", 19);
        return (84);
    }
    if (ac == 2 && my_str_isnum(argv[1])) {
        write(1, "\n", 1);
        return (0);
    }
    write(2, "Invalid arguments\n", 19);
    return (84);
}

void take_min(linked_list_t **l_a, linked_list_t *save, long *min, long *max)
{
    do {
        if (*min > (*l_a)->data)
            *min = (*l_a)->data;
        if (*max < (*l_a)->data)
            *max = (*l_a)->data;
        (*l_a) = (*l_a)->next;
    } while ((*l_a) != save);
}

long put_all_positive(linked_list_t **l_a)
{
    long min = (*l_a)->data;
    long max = (*l_a)->data;
    linked_list_t *save = (*l_a);

    take_min(l_a, save, &min, &max);
    if (min < 0) {
        min *= -1;
        save = (*l_a);
        do {
            (*l_a)->data += min;
            if (max < (*l_a)->data)
                max = (*l_a)->data;
            (*l_a) = (*l_a)->next;
        } while ((*l_a) != save);
    }
    (*l_a) = save;
    return (max);
}

long put_in_list(linked_list_t **l_a, int ac, char **argv)
{
    long max = 0;
    long num = 0;

    for (int i = 1; i < ac; i++) {
        if (!my_getnbr(argv[i], &num))
            append_nodes(l_a, num);
        else
            return (84);
    }
    return (0);
}

int main(int ac, char **argv)
{
    linked_list_t *l_a = NULL;
    linked_list_t *l_b = NULL;
    long max;
    char *output = malloc(sizeof(char) * 200000000);

    if (ac < 3)
        return (error_base(ac, argv));
    if (put_in_list(&l_a, ac, argv))
        return (84);
    max = put_all_positive(&l_a);
    if (check_if_sort(l_a)) {
        write(1, "\n", 1);
        return (0);
    }
    sort_linked_list(&l_a, &l_b, max, output);
    while ((l_a))
        remove_first(&l_a);
    free(output);
}

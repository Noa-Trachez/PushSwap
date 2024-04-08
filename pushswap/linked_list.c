/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-pushswap-noa.trachez
** File description:
** linked_list.c
*/

#include "pushswap.h"

void remove_first(linked_list_t **l_a)
{
    linked_list_t *tmp = (*l_a);

    if ((*l_a) == (*l_a)->next) {
        (*l_a) = NULL;
        return;
    }
    (*l_a)->previous->next = (*l_a)->next;
    (*l_a)->next->previous = (*l_a)->previous;
    (*l_a) = (*l_a)->next;
    free(tmp);
}

void append_nodes(linked_list_t **l_a, long data)
{
    linked_list_t *save = (*l_a);

    if (*l_a) {
        (*l_a) = (*l_a)->previous;
        (*l_a)->next = malloc(sizeof(linked_list_t));
        (*l_a)->next->data = data;
        (*l_a)->next->next = save;
        (*l_a)->next->previous = (*l_a);
        save->previous = (*l_a)->next;
        (*l_a) = save;
    } else {
        (*l_a) = malloc(sizeof(linked_list_t));
        (*l_a)->data = data;
        (*l_a)->next = (*l_a);
        (*l_a)->previous = (*l_a);
    }
}

void rotation(linked_list_t **l_a)
{
    if ((*l_a))
        (*l_a) = (*l_a)->next;
}

void allpop(linked_list_t **l_a, linked_list_t **l_b)
{
    if ((*l_a)) {
        append_nodes(l_b, (*l_a)->data);
        remove_first(l_a);
        (*l_b) = (*l_b)->previous;
    }
}

int check_if_sort(linked_list_t *l_a)
{
    linked_list_t *save = l_a->previous;

    do {
        if (l_a->data <= l_a->next->data)
            l_a = l_a->next;
        else
            break;
    } while (save != l_a);
    if (l_a == save)
        return (1);
    else
        return (0);
}

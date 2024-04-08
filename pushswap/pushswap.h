/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-pushswap-noa.trachez
** File description:
** pushswap.h
*/

#ifndef PUSH_H_
    #define PUSH_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>

typedef struct linked_list {
    struct linked_list *next;
    struct linked_list *previous;
    long data;
} linked_list_t;

int my_str_isnum(char const *str);
long my_getnbr(char const *str, long *num);
char *my_strcpy(char *dest, char const *src);
long long power_nbr(long long power);
long len_nbr(long max);
void continue_algo_sort(linked_list_t **l_a, linked_list_t **l_b,
long long *nbr, char *output);
void algo_sort(linked_list_t **l_a, linked_list_t **l_b,
long long *nbr, char *output);
void sort_linked_list(linked_list_t **l_a, linked_list_t **l_b,
long max, char *output);
void remove_first(linked_list_t **l_a);
void append_nodes(linked_list_t **l_a, long data);
void rotation(linked_list_t **l_a);
void allpop(linked_list_t **l_a, linked_list_t **l_b);
int check_if_sort(linked_list_t *l_a);

#endif

/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-pushswap-noa.trachez
** File description:
** my_lib.c
*/

#include "pushswap.h"

int my_str_isnum(char const *str)
{
    int answer = 1;
    int range_sign = 0;
    while (str[range_sign] == '-' || str[range_sign] == '+')
        range_sign++;
    for (; str[range_sign] != '\0'; range_sign++) {
        if (str[range_sign] >= 48 && str[range_sign] <= 57) {
            answer = 1;
        } else {
            return (0);
        }
    }
    return (answer);
}

static long sign_check(char const *str, long *range)
{
    long quotient = 0;

    for (long i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-') {
            quotient += 1;
        }
        *range = i + 1;
    }
    if (quotient % 2 == 1)
        return (-1);
    else
        return (1);
}

static long nbr_check(char const *str, long *range, long *quotient, long *num)
{
    long my_number = 0;

    for (long i = *range; str[i] >= '0' && str[i] <= '9'; i++) {
        if (my_number > (2147483648 - (str[i] - 48)) / 10) {
            return (84);
        }
        if (*quotient == 1 && my_number > (2147483647 - (str[i] - 48)) / 10) {
            return (84);
        }
        my_number = (my_number * 10) + (str[i] - 48);
    }
    my_number *= *quotient;
    *num = my_number;
    return (0);
}

long my_getnbr(char const *str, long *num)
{
    long quotient;
    long range = 0;

    if (!my_str_isnum(str))
        return (84);
    quotient = sign_check(str, &range);
    if (nbr_check(str, &range, &quotient, num))
        return (84);
    return (0);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = src[i];
    return (dest);
}

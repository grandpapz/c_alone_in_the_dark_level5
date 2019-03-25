/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rpn_calc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:28 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/25 18:03:01 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    spaces(char *s, int *i)
{
    int j;

    j = *i;
    while (s[j] == ' ')
        j++;
    *i = j;
}

void    skip_numbers(char *s, int *i)
{
    int j;

    j = *i;
    while (s[j] >= '0' && s[j] <= '9')
        j++;
    *i = j;
}

int     operations(int nb, char sign, int nb2)
{
    if (sign == '+')
        return (nb + nb2);
    if (sign == '-')
        return (nb - nb2);
    if (sign == '*')
        return (nb * nb2);
    if (sign == '/')
        return (nb / nb2);
    if (sign == '%')
        return (nb % nb2);
    return (0);
}

int     rpn_calc(char *s)
{
    int    tab[2000];
    int    i;
    int    j;

    i = -1;
    j = 0;
    while (s[++i])
    {
        spaces(s, &i);
        if ((s[i] >= '0' && s[i] <= '9') || ((s[i] == '+' || s[i] == '-') &&
        (s[i + 1] >= '0' && s[i + 1] <= '9')))
        {
            tab[j++] = atoi(&s[i++]);
            skip_numbers(s, &i);
        }
        if (((s[i] == '+' || s[i] == '-') && (s[i + 1] == ' ' ||
        s[i + 1] == '\0')) || (s[i] == '*' || s[i] == '/' || s[i] == '%'))
        {
            if (j < 1 || ((s[i] == '%' || s[i] == '/') && tab[j - 1] == 0))
                return(printf("Error\n"));
            tab[j - 2] = operations(tab[j - 2], s[i], tab[j - 1]);
            j--;
        }
    }
    if (j != 1)
        return(printf("Error\n"));
    return(printf("%d\n", tab[0]));
}

int     main(int argc, char **argv)
{
    if (argc == 2)
        rpn_calc(argv[1]);
    else
        printf("Error\n");
    return (0);
}

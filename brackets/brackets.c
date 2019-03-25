/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brackets.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:01:01 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/25 18:03:22 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     isopen(char c)
{
    if (c == '(' || c == '[' || c == '{')
        return (1);
    return (0);
}

int     isclosed(char c)
{
    if (c == ')' || c == ']' || c == '}')
        return (1);
    return (0);
}

int     ismatch(char a, char b)
{
    if (a == '(' && b == ')')
        return (1);
    if (a == '[' && b == ']')
        return (1);
    if (a == '{' && b == '}')
        return (1);
    return (0);
}

int     brackets(char *s)
{
    char    array[2000];
    int     i;
    int     j;

    i = 0;
    j = -1;
    while (s[i])
    {
        if (isopen(s[i]))
        {
            j++;
            array[j] = s[i];
        }
        else if (isclosed(s[i]))
        {
            if (j >= 0 && ismatch(array[j], s[i]))
                j--;
            else
                return (0);    
        }
        i++;
    }
    if (j == -1)
        return (1);
    return (0);
}

int     main(int argc, char **argv)
{
    int i;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        if (brackets(argv[i]))
            write(1, "OK\n", 3);
        else
            write(1, "Error\n", 6);
        i++;
    }
    return (0);
}

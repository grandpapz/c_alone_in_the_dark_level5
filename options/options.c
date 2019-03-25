/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:01:36 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/25 18:02:14 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
    int j;
	int options[32] = {0};

	if (argc == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] == '-')
		{
			while (argv[i][j] && argv[i][j] >= 'a' && argv[i][j] <= 'z')
			{
				if (argv[i][j] == 'h')
				{
					write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
					return (0);
				}
				options['z' - argv[i][j] + 6] = 1;
				j++;
			}
			if (argv[i][j])
			{
				write(1, "Invalid Option\n", 15);
				return (0);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 32)
	{
		options[i] = '0' + options[i];
		write(1, &options[i++], 1);
		if (i == 32)
			write(1, "\n", 1);
		else if (i % 8 == 0)
			write(1, " ", 1);
	}
	return (0);
}

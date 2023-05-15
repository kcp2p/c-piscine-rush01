/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krchuaip@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:40:50 by krchuaip          #+#    #+#             */
/*   Updated: 2023/05/15 16:16:32 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper_utils.h"
#include <stdlib.h>
#include <unistd.h>

int	solve(int tab[SIZE][SIZE], int entry[SIZE_SIZE], int pos)
{
	int	size;

	if (pos == SIZE_SIZE)
		return (1);
	size = 0;
	while (++size <= SIZE)
	{
		if (pass_check_double(tab, pos, size))
		{
			tab[pos / SIZE][pos % SIZE] = size;
			if (pass_check_all(tab, pos, entry))
			{
				if (solve(tab, entry, pos + 1))
					return (1);
			}
			else
				tab[pos / SIZE][pos % SIZE] = 0;
		}
	}
	return (0);
}

void	print_solution(int tab[SIZE][SIZE])
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			ft_putnbr(tab[i][j]);
			if (!(j == (SIZE - 1)))
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	main(int argc, char **argv)
{
	int	tab[SIZE][SIZE];
	int	*entry;

	if (fail_check_arg(argc, argv))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	entry = get_numbers(argv[1]);
	if (entry && solve(tab, entry, 0))
		print_solution(tab);
	else
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	free(entry);
	return (0);
}

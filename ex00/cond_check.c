/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krchuaip@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:47:44 by krchuaip          #+#    #+#             */
/*   Updated: 2023/05/14 21:44:10 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper_utils.h"

int	pass_check_double(int tab[SIZE][SIZE], int pos, int num)
{
	int	i;

	i = -1;
	while (++i < pos / SIZE)
		if (tab[i][pos % SIZE] == num)
			return (0);
	i = -1;
	while (++i < pos % SIZE)
		if (tab[pos / SIZE][i] == num)
			return (0);
	return (1);
}

int	fail_up_col(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE])
{
	int	i;
	int	max;
	int	visible_towers;

	i = 0;
	max = 0;
	visible_towers = 0;
	if (pos / SIZE == (SIZE - 1))
	{
		while (i < SIZE)
		{
			if (tab[i][pos % SIZE] > max)
			{
				max = tab[i][pos % SIZE];
				visible_towers++;
			}
			i++;
		}
		if (entry[pos % SIZE] != visible_towers)
			return (1);
	}
	return (0);
}

int	fail_down_col(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE])
{
	int	i;
	int	max;
	int	visible_towers;

	i = SIZE - 1;
	max = 0;
	visible_towers = 0;
	if (pos / SIZE == (SIZE - 1))
	{
		while (i >= 0)
		{
			if (tab[i][pos % SIZE] > max)
			{
				max = tab[i][pos % SIZE];
				visible_towers++;
			}
			i--;
		}
		if (entry[(SIZE * 1) + pos % SIZE] != visible_towers)
			return (1);
	}
	return (0);
}

int	fail_left_row(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE])
{
	int	i;
	int	max;
	int	visible_towers;

	i = 0;
	max = 0;
	visible_towers = 0;
	if (pos % SIZE == (SIZE - 1))
	{
		while (i < SIZE)
		{
			if (tab[pos / SIZE][i] > max)
			{
				max = tab[pos / SIZE][i];
				visible_towers++;
			}
			i++;
		}
		if (entry[(SIZE * 2) + pos / SIZE] != visible_towers)
			return (1);
	}
	return (0);
}

int	fail_right_row(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE])
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = SIZE;
	max_size = 0;
	visible_towers = 0;
	if (pos % SIZE == (SIZE - 1))
	{
		while (--i >= 0)
		{
			if (tab[pos / SIZE][i] > max_size)
			{
				max_size = tab[pos / SIZE][i];
				visible_towers++;
			}
		}
		if (entry[(SIZE * 3) + pos / SIZE] != visible_towers)
			return (1);
	}
	return (0);
}

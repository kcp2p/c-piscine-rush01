/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krchuaip@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:46:06 by krchuaip          #+#    #+#             */
/*   Updated: 2023/05/13 15:11:13 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper_utils.h"
#include <stdlib.h>

int	fail_check_arg(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]))
		return (0);
	return (1);
}

int	check_num(char *str, int *tab)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = 0;
	count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (++count > SIZE_SIZE)
				return (0);
			tab[j++] = ft_atoi(str + i);
		}
		else if (str[i] != ' ' && str[i] != '\n')
			return (0);
	}
	return (1);
}

int	*get_numbers(char *str)
{
	int	*tab;

	tab = malloc(sizeof(int) * SIZE_SIZE);
	if (!(tab))
		return (0);
	if (!(check_num(str, tab)))
	{
		free(tab);
		return (0);
	}
	return (tab);
}

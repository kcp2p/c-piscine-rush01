/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krchuaip@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:22:29 by krchuaip          #+#    #+#             */
/*   Updated: 2023/05/15 16:18:00 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	num;
	int	pos;

	num = 0;
	pos = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pos *= -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			num = (num * 10) + (*str - '0');
		else
			break ;
		str++;
	}
	return (num * pos);
}

void	ft_putnbr(int num)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num < 10)
		ft_putchar(num + '0');
	else
	{
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + '0');
	}
}

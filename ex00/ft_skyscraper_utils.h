/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krchuaip@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:41:44 by krchuaip          #+#    #+#             */
/*   Updated: 2023/05/15 16:17:35 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SKYSCRAPER_UTILS_H
# define FT_SKYSCRAPER_UTILS_H

// SIZE
# define SIZE 4

// SIZE^2
# define SIZE_SIZE 16

// STDIO I/O
# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);

int		ft_atoi(char *str);
int		ft_strlen(char *str);

// Parse number
int		*get_numbers(char *str);

// Checking conditions
int		fail_check_arg(int argc, char **argv);
int		pass_check_all(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE]);
int		pass_check_double(int tab[SIZE][SIZE], int pos, int num);
int		fail_up_col(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE]);
int		fail_down_col(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE]);
int		fail_left_row(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE]);
int		fail_right_row(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE]);
#endif
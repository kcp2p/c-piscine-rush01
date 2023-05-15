/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krchuaip@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:50:37 by krchuaip          #+#    #+#             */
/*   Updated: 2023/05/13 15:10:05 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper_utils.h"

int	pass_check_all(int tab[SIZE][SIZE], int pos, int entry[SIZE_SIZE])
{
	if (fail_up_col(tab, pos, entry) \
			|| fail_down_col(tab, pos, entry) \
			|| fail_left_row(tab, pos, entry) \
			|| fail_right_row(tab, pos, entry))
		return (0);
	return (1);
}

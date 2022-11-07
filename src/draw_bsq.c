/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:59:05 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/07 19:39:49 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/draw_bsq.h"

char	**draw_bsq(char **map, int n_rows, t_square bsq)
{
	int	row;
	int	col;

	row = 1;
	col = 0;
	while (row < n_rows)
	{
		while (col < str_len(map[1]))
		{
			if ((bsq.sp_row <= row && row <= bsq.ep_row) \
				&& (bsq.sp_col <= col && col <= bsq.ep_col))
			{
				map[row][col] = map[0][str_len(map[0]) - 2];
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (map);
}

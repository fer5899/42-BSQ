/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:59:05 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/08 09:45:55 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/insert_bsq.h"

char	**insert_bsq(char **map, int n_rows, t_square bsq)
{
	int	row;
	int	col;

	row = 1;
	col = 0;
	while (row < n_rows)
	{
		while (col < str_len(map[1]))
		{
			if ((bsq.sp.row <= row && row <= bsq.ep.row) \
				&& (bsq.sp.col <= col && col <= bsq.ep.col))
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

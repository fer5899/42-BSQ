/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:51:35 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/08 09:48:41 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/structs.h"
#include "../inc/print_map.h"

void	init_sq(t_square *sq, int max_row, int max_col)
{
	sq->sp.row = max_row;
	sq->sp.col = max_col;
	sq->ep.row = max_row;
	sq->ep.col = max_col;
}

int	sq_is_valid(t_square bsq, t_point *obs_arr, int n_obs)
{
	int	i;

	i = 0;
	while (i < n_obs)
	{
		if ((bsq.sp.row <= obs_arr[i].row && obs_arr[i].row <= bsq.ep.row) &&\
			(bsq.sp.col <= obs_arr[i].col && obs_arr[i].col <= bsq.ep.col))
			return (0);
		i++;
	}
	return (1);
}

t_square	compare_squares(t_square bsq, t_square next_bsq)
{
	int bsq_side;
	int	next_bsq_side;

	bsq_side = bsq.ep.row - bsq.sp.row;
	next_bsq_side = next_bsq.ep.row - next_bsq.sp.row;
	if (bsq_side > next_bsq_side)
		return (bsq);
	else
		return (next_bsq);
}

// t_square	find_bsq(char **map, int n_rows, t_point *obs_arr, int n_obs)
// {
// 	t_square	bsq;
// 	t_square	next_bsq;
// 	int			row;
// 	int			col;
// 	int			max_cols;

// 	row = n_rows; // itera hasta 1
// 	max_cols = str_len(map[1]);
// 	col = max_cols; // itera hasta 0
// 	init_sq(&bsq, n_rows, max_cols);
// 	while (row > 1)
// 	{
// 		while (col > 0)
// 		{
// 			if (map[row][col] != map[0][str_len(map[0]) - 3])
// 				// Find biggest square from this row col and store in next_bsq
// 				bsq = compare_squares(bsq, next_bsq);
// 			col--;
// 		}
// 		col = max_cols;
// 		row--;
// 	}
// 	// Si bsq final es bsq caso base y hay obstaculo en ese sitio, devuelve bsq con -1
// }

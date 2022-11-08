/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:51:35 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/08 16:59:24 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

#include <stdio.h>

t_square	get_start_sq(int n_rows, int n_cols, t_point sp)
{
	t_square	start_sq;
	int			sq_side;
	int			max_row_idx;
	int			max_col_idx;

	max_row_idx = n_rows - 1;
	max_col_idx = n_cols - 1;
	if ((max_row_idx - sp.row) <= (max_col_idx - sp.col))
		sq_side = (max_row_idx - sp.row);
	else
		sq_side = (max_col_idx - sp.col);
	start_sq.sp = sp;
	start_sq.ep.row = sp.row + sq_side;
	start_sq.ep.col = sp.col + sq_side;
	return (start_sq);
}

// t_square	find_bsq(char **map, int n_rows, t_point *obs_arr)
// {
// 	t_square	bsq;
// 	t_square	next_bsq;
// 	t_point		sp;
// 	int			n_cols;

// 	n_cols = str_len(map[1]);
// 	init_pt(&sp, n_rows, n_cols);
// 	init_sq(&bsq, n_rows, n_cols);
// 	while (sp.row > 1)
// 	{
// 		while (sp.col > 0)
// 		{
// 			if (map[sp.row][sp.col] != map[0][str_len(map[0]) - 3])
// 				// Find biggest square from this row col and store in next_bsq
// 				bsq = compare_squares(bsq, next_bsq);
// 			sp.col--;
// 		}
// 		sp.col = n_cols;
// 		sp.row--;
// 	}
// 	// Si bsq final es bsq caso base y hay obstaculo en ese sitio, devuelve bsq con -1
// }

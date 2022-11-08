/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:51:35 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/08 12:43:30 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

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

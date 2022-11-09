/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:51:35 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/09 10:01:01 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

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

int	sq_size(t_square sq)
{
	return (sq.ep.row - sq.sp.row);
}

t_square	rec_find_bsq(t_square sq, t_square minsq, t_point *obs_arr)
{
	if (sq_size(sq) < sq_size(minsq))
		return (init_sq(init_pt(0, 0), init_pt(-1, -1)));
	if (!sq_is_valid(sq, obs_arr))
	{
		sq.ep.row--;
		sq.ep.col--;
		return (rec_find_bsq(sq, minsq, obs_arr));
	}
	else
		return (sq);
}

t_square	get_bsq(t_square ssq, t_square bsq, t_square *nsq, t_point *oarr)
{
	*nsq = rec_find_bsq(ssq, bsq, oarr);
	bsq = compare_squares(bsq, *nsq);
	return (bsq);
}

#include <stdio.h>

t_square	p_find_bsq(char **map, int n_rows, t_point *obs_arr)
{
	t_square	bsq;
	
	bsq = init_sq(init_pt(0, 0), init_pt(-1, -1));
	if (map[1] == NULL)
	{
		free(obs_arr);
		return (bsq);
	}
	if (count_obstacles(map, n_rows) == ((n_rows - 1) * (str_len(map[1]) - 1)))
	{
		free(obs_arr);
		return (bsq);
	}
	find_bsq(map, n_rows, obs_arr);
	return (bsq);
}

t_square	find_bsq(char **map, int n_rows, t_point *obs_arr)
{
	t_square	bsq;
	t_square	next_bsq;
	t_square	start_sq;
	t_point		sp;

	sp = init_pt(n_rows - 1, str_len(map[1]) - 2);
	bsq = init_sq(sp, sp);
	while (sp.row >= 1)
	{
		while (sp.col >= 0)
		{
			if (map[sp.row][sp.col] != map[0][str_len(map[0]) - 3])
			{
				start_sq = get_start_sq(n_rows, str_len(map[1]) - 1, sp);
				next_bsq = rec_find_bsq(start_sq, bsq, obs_arr);
				bsq = compare_squares(bsq, next_bsq);
			}
			sp.col--;
		}
		sp.col = str_len(map[1]) - 2;
		sp.row--;
	}
	free(obs_arr);
	return (bsq);
}

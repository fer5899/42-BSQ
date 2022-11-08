/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:59:05 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/08 12:45:07 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

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
		if ((bsq.sp.row <= obs_arr[i].row && obs_arr[i].row <= bsq.ep.row) && \
			(bsq.sp.col <= obs_arr[i].col && obs_arr[i].col <= bsq.ep.col))
			return (0);
		i++;
	}
	return (1);
}

t_square	compare_squares(t_square bsq, t_square next_bsq)
{
	int	bsq_side;
	int	next_bsq_side;

	bsq_side = bsq.ep.row - bsq.sp.row;
	next_bsq_side = next_bsq.ep.row - next_bsq.sp.row;
	if (bsq_side > next_bsq_side)
		return (bsq);
	else
		return (next_bsq);
}

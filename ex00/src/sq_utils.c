/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:59:05 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/09 12:39:35 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

t_pt	init_pt(int row, int col)
{
	t_pt	pt;

	pt.row = row;
	pt.col = col;
	return (pt);
}

t_sq	init_sq(t_pt sp, t_pt ep)
{
	t_sq	sq;

	sq.sp.row = sp.row;
	sq.sp.col = sp.col;
	sq.ep.row = ep.row;
	sq.ep.col = ep.col;
	return (sq);
}

int	obs_arr_len(t_pt *obs_arr)
{
	int	len;

	len = 0;
	while (obs_arr[len].row != -1)
		len++;
	return (len);
}

int	sq_is_valid(t_sq bsq, t_pt *obs_arr)
{
	int	i;

	i = 0;
	while (i < obs_arr_len(obs_arr))
	{
		if ((bsq.sp.row <= obs_arr[i].row && obs_arr[i].row <= bsq.ep.row) && \
			(bsq.sp.col <= obs_arr[i].col && obs_arr[i].col <= bsq.ep.col))
			return (0);
		i++;
	}
	return (1);
}

t_sq	compare_squares(t_sq bsq, t_sq next_bsq)
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

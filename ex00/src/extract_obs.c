/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_obs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:08:50 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/09 12:39:35 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

int	count_obstacles(char **map, int n_rows)
{
	t_pt	pt;
	int		n_obs;
	char	obs_char;

	pt = init_pt(1, 0);
	n_obs = 0;
	obs_char = map[0][str_len(map[0]) - 3];
	while (pt.row < n_rows)
	{
		while (pt.col < str_len(map[1]))
		{
			if (map[pt.row][pt.col] == obs_char)
				n_obs++;
			pt.col++;
		}
		pt.col = 0;
		pt.row++;
	}
	return (n_obs);
}

t_pt	*create_obs_arr(char **map, int n_rows)
{
	t_pt	*obs_arr;
	int		n_obs;

	n_obs = (count_obstacles(map, n_rows) + 1);
	obs_arr = pt_malloc(n_obs);
	return (obs_arr);
}

t_pt	*extract_obstacles(char **map, int n_rows)
{
	t_pt	pt;
	t_pt	*obs_arr;
	t_pt	*aux;

	pt = init_pt(1, 0);
	obs_arr = create_obs_arr(map, n_rows);
	aux = obs_arr;
	while (pt.row < n_rows)
	{
		while (pt.col < str_len(map[1]))
		{
			if (map[pt.row][pt.col] == map[0][str_len(map[0]) - 3])
			{
				*obs_arr = init_pt(pt.row, pt.col);
				obs_arr++;
			}
			pt.col++;
		}
		pt.col = 0;
		pt.row++;
	}
	*obs_arr = init_pt(-1, -1);
	return (aux);
}

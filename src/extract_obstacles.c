/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_obstacles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:08:50 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/08 09:46:52 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/extract_obstacles.h"

int	count_obstacles(char **map, int n_rows)
{
	int		row;
	int		col;
	int		n_obs;
	char	obs_char;

	row = 1;
	col = 0;
	n_obs = 0;
	obs_char = map[0][str_len(map[0]) - 3];
	while (row < n_rows)
	{
		while (col < str_len(map[1]))
		{
			if (map[row][col] == obs_char)
				n_obs++;
			col++;
		}
		col = 0;
		row++;
	}
	return (n_obs);
}

t_point	*extract_obstacles(char **map, int n_rows, int *n_obs)
{
	int		row;
	int		col;
	t_point	*obs_arr;
	t_point	*aux;

	row = 1;
	col = 0;
	*n_obs = count_obstacles(map, n_rows);
	obs_arr = (t_point *) malloc(sizeof(*obs_arr) * *n_obs);
	aux = obs_arr;
	while (row < n_rows)
	{
		while (col < str_len(map[1]))
		{
			if (map[row][col] == map[0][str_len(map[0]) - 3])
			{
				obs_arr->row = row;
				(obs_arr++)->col = col;
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (aux);
}


// TESTING

#include "../inc/get_map.h"
#include "../inc/draw_bsq.h"
#include <stdio.h>

int	sq_is_valid(t_square bsq, t_point *obs_arr, int n_obs);

int	main(void)
{
	t_point	*obs_arr;
	int		n_rows;
	char	**map;
	int		obs_idx;
	int		n_obs;
	t_square	bsq;

	n_rows = 0;
	obs_idx = 0;
	n_obs = 0;
	bsq.sp.row = 4;
	bsq.sp.col = 0;
	bsq.ep.row = 5;
	bsq.ep.col = 4;
	
	map = get_map("../maps/map1", &n_rows);
	// printf("%d\n", n_rows);
	print_map(map, n_rows);
	obs_arr = extract_obstacles(map, n_rows, &n_obs);
	map = draw_bsq(map, n_rows, bsq);
	write(1, "\n", 1);
	print_map(map, n_rows);
	printf("\nSquare is valid: %d\n\n", sq_is_valid(bsq, obs_arr, n_obs));
	//printf("%d\n", count_obstacles(map, n_rows));
	while (obs_idx < n_obs)
	{
		printf("obstacle %d, row: %d, col: %d\n", obs_idx, \
			obs_arr[obs_idx].row, obs_arr[obs_idx].col);
		obs_idx++;
	}
	//init_sq(&bsq, 0, 0);
	//printf("sp_row %d, sp_col: %d, ep_row: %d, ep_col: %d\n", bsq.sp.row, \
			bsq.sp.col, bsq.ep.row, bsq.ep.col);
}

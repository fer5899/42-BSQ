/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_obstacles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:08:50 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/07 18:08:08 by fgomez-d         ###   ########.fr       */
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

t_obs	*extract_obstacles(char **map, int n_rows, int *n_obs)
{
	int		row;
	int		col;
	t_obs	*obs_arr;
	t_obs	*aux;

	row = 1;
	col = 0;
	*n_obs = count_obstacles(map, n_rows);
	obs_arr = (t_obs *) malloc(sizeof(*obs_arr) * *n_obs);
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

/* 

// TESTING

#include "../inc/get_map.h"
#include <stdio.h>

int	main(void)
{
	t_obs	*obs_arr;
	int		n_rows;
	char	**map;
	int		obs_idx;
	int		n_obs;

	n_rows = 0;
	obs_idx = 0;
	n_obs = 0;
	map = get_map("../maps/map1", &n_rows);
	print_map(map, n_rows);
	obs_arr = extract_obstacles(map, n_rows, &n_obs);
	printf("%d\n", count_obstacles(map, n_rows));
	while (obs_idx < n_obs)
	{
		printf("obstacle %d, row: %d, col: %d\n", obs_idx, \
			obs_arr[obs_idx].row, obs_arr[obs_idx].col);
		obs_idx++;
	}
}
 */
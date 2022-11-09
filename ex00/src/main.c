/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:34:02 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/09 12:40:14 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

void	iterate_args(int argc, char **argv)
{
	char		**map;
	t_sq		bsq;
	int			n_rows;
	int			arg_idx;

	arg_idx = 1;
	while (arg_idx < argc)
	{
		n_rows = 0;
		map = get_map(argv[arg_idx], &n_rows, 1);
		if (check_map(map, n_rows) == 0)
			write(1, "map error\n", 11);
		else
		{
			bsq = p_find_bsq(map, n_rows, extract_obstacles(map, n_rows));
			if (bsq.ep.row != -1)
			{
				insert_bsq(map, n_rows, bsq);
			}
			print_map(map, n_rows);
		}
		free_map(map, n_rows);
		arg_idx++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		stdin_launch();
	else
	{
		iterate_args(argc, argv);
	}
	system ("leaks -q bsq");
	return (0);
}

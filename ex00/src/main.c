/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:34:02 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/08 19:49:21 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

int	main(int argc, char **argv)
{
	int			aux;
	int			n_rows;
	char		**map;
	t_square	bsq;

	bsq = init_sq(init_pt(0, 0), init_pt(-1, -1));
	aux = 0;
	if (argc == 1)
		stdin_bsq();
	else
	{
		aux = 1;
		while (aux < argc)
		{
			n_rows = 0;
			map = get_map(argv[aux], &n_rows);
			if (check_map(map, n_rows) == 0)
				write(1, "map error\n", 11);
			else
			{
				bsq = find_bsq(map, n_rows, extract_obstacles(map, n_rows));
				if (bsq.ep.row != -1)
					insert_bsq(map, n_rows, bsq);
				print_map(map, n_rows);
			}
			aux++;
		}
	}
	return (0);
}

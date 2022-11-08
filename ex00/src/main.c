/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:34:02 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/08 12:22:08 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

int	main(int argc, char **argv)
{
	int			aux;
	int			rows_number;
	char		**act_map;
	char		ch;
	char		stdin_map[100];
	t_square	bsq;

	bsq.sp.row = 1;
	bsq.sp.col = 0;
	bsq.ep.row = 2;
	bsq.ep.col = 3;
	aux = 0;
	if (argc == 1)
	{
		while(read(0, &ch, 1) > 0 && ch != 27)
		{
			stdin_map[aux] = ch;
			aux++;
		}
		rows_number = 0;
		act_map = get_map_stdin(stdin_map, &rows_number);
		print_map(act_map, rows_number);
	}
	else
	{
		aux = 1;
		while (aux < argc)
		{
			rows_number = 0;
			act_map = get_map(argv[aux], &rows_number);
			if (check_map(act_map, rows_number) == 0)
				write(1, "map error\n", 11);
			//insert_bsq(act_map, rows_number, bsq);
			print_map(act_map, rows_number);
			aux++;
		}
	}
	return (1);
}

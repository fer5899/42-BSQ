/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramos-l <bramos-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:34:02 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/07 16:34:15 by bramos-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	**get_map(char *namefile, int *n_rows);
int		check_map(char **map, int row_number);

int	main(int argc, char **argv)
{
	int		aux;
	int		rows_number;
	char	**act_map;

	aux = 1;
	if (argc == 1)
		return (1);
	else
	{
		while (aux < argc)
		{
			rows_number = 0;
			act_map = get_map(argv[aux], &rows_number);
			if (check_map(act_map, rows_number) == 0)
				write(1, "map error\n", 11);
			aux++;
		}
	}
	return (1);
}

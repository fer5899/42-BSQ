/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:27:48 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/08 23:16:37 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

char	*map_to_string(char *namefile)
{
	int		file_adress;
	int		aux;
	char	*str;

	str = c_malloc(1);
	file_adress = open (namefile, O_RDONLY);
	aux = 1;
	if (file_adress == -1)
		write (1, "map error\n", 10);
	else
	{
		while (read(file_adress, str, 1) != 0)
			aux++;
		free(str);
		str = c_malloc(--aux);
		file_adress = open(namefile, O_RDONLY);
		read(file_adress, str, aux);
	}
	if (close(file_adress) == -1)
		write(1, "map error\n", 10);
	return (str);
}

int	row_number(char *str)
{
	t_point	auxpt;

	auxpt = init_pt(0, 1);
	while (str[auxpt.row] != '\0')
	{
		if (str[auxpt.row] == '\n')
			auxpt.col++;
		auxpt.row++;
	}
	return (auxpt.col);
}

int	col_number(char *str)
{
	t_point	auxpt;
	int		result;

	auxpt = init_pt(0, 0);
	result = 0;
	while (str[auxpt.row++] != '\0')
	{
		while (auxpt.col == 1 && str[auxpt.row] != '\n')
		{
			if (str[auxpt.row] == '\0')
				return (result);
			result++;
			auxpt.row++;
		}
		if (str[auxpt.row] == '\n')
			auxpt.col++;
	}
	return (result);
}

char	**get_map(char *namefile, int *n_rows)
{
	char	*ol_map;
	t_point	auxpt;
	int		i;
	char	**map;
	ol_map = map_to_string(namefile);
	*n_rows = row_number(ol_map) - 1;
	map = cc_malloc(*n_rows + 1);
	i = 0;
	auxpt = init_pt(0, 0);
	while (ol_map[auxpt.row] != '\0')
	{
		map[i] = c_malloc(col_number(ol_map) + 2);
		auxpt.col = 0;
		while (ol_map[auxpt.row] != '\n')
			map[i][auxpt.col++] = ol_map[auxpt.row++];
		map[i][auxpt.col] = ol_map[auxpt.row++];
		map[i][++auxpt.col] = '\0';
		i++;
	}
	if (*n_rows != i)
		map[0] = "xx";
	free(ol_map);
	return (map);
}

char	**get_map_stdin(char *ol_map, int *n_rows)
{
	t_point	auxpt;
	int		i;
	char	**map;

	*n_rows = row_number(ol_map) - 1;
	map = cc_malloc(*n_rows);
	i = 0;
	auxpt.row = 0;
	while (ol_map[auxpt.row] != '\0')
	{
		map[i] = c_malloc(col_number(ol_map) + 2);
		auxpt.col = 0;
		while (ol_map[auxpt.row] != '\n')
			map[i][auxpt.col++] = ol_map[auxpt.row++];
		map[i][auxpt.col] = ol_map[auxpt.row++];
		map[i][++auxpt.col] = '\0';
		i++;
	}
	free(ol_map);
	return (map);
}

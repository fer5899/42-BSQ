/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:27:48 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/09 12:39:35 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"
#include <stdio.h>

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
		if (count_line_jumps(str) == 0)
			rewrite_for_error(str);
	}
	if (close(file_adress) == -1)
		write(1, "map error\n", 10);
	return (str);
}

int	row_number(char *str)
{
	t_pt	auxpt;

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
	t_pt	auxpt;
	int		result;
	int		aux;

	aux = 0;
	while (str[aux] != '\n')
		aux++;
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
	if (aux > result)
		result = aux;
	return (result);
}

char	**get_map(char *namefile, int *n_rows, int input)
{
	char	*ol_map;
	t_pt	auxpt;
	int		i;
	char	**map;

	ol_map = get_ol_map(namefile, input);
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

char	*get_ol_map(char *str, int input)
{
	char	*result;

	result = NULL;
	if (input == 0)
		result = read_stdin(result);
	else
		result = map_to_string(str);
	return (result);
}

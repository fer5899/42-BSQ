/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:27:48 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/07 18:28:51 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_map.h"
#include "../inc/check_map.h"
#include <stdio.h>

char	*map_to_string(char *namefile)
{
	int		file_adress;
	int		aux;
	int		closing_result;
	char	*str;

	str = malloc(sizeof(char) * 1);
	file_adress = open (namefile, O_RDONLY);
	aux = 1;
	if (file_adress == -1)
		write (1, "map error\n", 10);
	else
	{
		while (read(file_adress, str, 1) != 0)
			aux++;
		free(str);
		str = (char *) malloc(sizeof(char) * --aux);
		file_adress = open (namefile, O_RDONLY);
		read(file_adress, str, aux);
	}
	closing_result = close(file_adress);
	if (closing_result == -1)
		write(1, "map error\n", 10);
	return (str);
}

int	row_number(char *str)
{
	int	auxrows;
	int	auxcols;

	auxcols = 1;
	auxrows = 0;
	while (str[auxrows] != '\0')
	{
		if (str[auxrows] == '\n')
			auxcols++;
		auxrows++;
	}
	return (auxcols);
}

int	col_number(char *str)
{
	int	aux;
	int	auxcols;
	int	result;

	auxcols = 0;
	aux = 0;
	result = 0;
	while (str[aux++] != '\0')
	{
		while (auxcols == 1 && str[aux] != '\n')
		{
			result++;
			aux++;
		}
		if (str[aux] == '\n')
			auxcols++;
	}
	return (result);
}

char	**get_map(char *namefile, int *n_rows)
{
	char	*ol_map;
	int		auxrows;
	int		auxcols;
	int		i;
	char	**map;

	ol_map = map_to_string(namefile);
	*n_rows = row_number(ol_map) - 1;
	map = (char **) malloc(sizeof(char *) * *n_rows);
	i = 0;
	auxrows = 0;
	while (ol_map[auxrows] != '\0')
	{
		map[i] = (char *) malloc(sizeof(char) * col_number(ol_map) + 2);
		auxcols = 0;
		while (ol_map[auxrows] != 10)
			map[i][auxcols++] = ol_map[auxrows++];
		map[i][auxcols] = ol_map[auxrows++];
		map[i][++auxcols] = '\0';
		i++;
	}
	free(ol_map);
	return (map);
}

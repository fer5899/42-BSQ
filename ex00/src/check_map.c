/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:32:11 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/08 12:21:45 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
		{
			return (1);
		}
		else if (s1[i] < s2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	a_to_i(char *numb)
{
	int	result;
	int	aux;

	if (str_len(numb) > 10)
		return (-1);
	else if (str_len(numb) == 10 && ft_strcmp(numb, "2147483647") == 1)
		return (-1);
	aux = 0;
	result = 0;
	while (aux < str_len(numb))
	{
		result = result * 10 + (numb[aux] - 48);
		aux++;
	}
	return (result);
}

int	info_rows(char *info)
{
	int		aux;
	char	*rows_info;
	int		result;

	aux = 0;
	rows_info = (char *) malloc(sizeof(char) * str_len(info));
	while (aux < str_len(info) - 4)
	{
		rows_info[aux] = info[aux];
		aux++;
	}
	rows_info[aux] = '\0';
	result = a_to_i(rows_info);
	free(rows_info);
	return (result);
}

int	check_chars_in_line(char **map, int i)
{
	int	aux;
	int	x;

	x = str_len(map[0]);
	aux = 0;
	while (map[1][aux] != '\n')
	{
		if (map[i][aux] != map[0][x - 4] && map[i][aux] \
		!= map[0][x - 3] && map[i][aux] != map[0][x - 2])
			return (0);
		aux++;
	}
	return (1);
}

int	check_map(char **map, int row_number)
{
	int	i;
	int	x;
	int	aux;

	i = 1;
	x = str_len(map[0]);
	if (info_rows(map[0]) != row_number - 1)
		return (0);
	while (i < row_number)
	{
		if (str_len(map[i]) != str_len(map[1]))
			return (0);
		if (map[0][x - 4] == map[0][x - 3] || map[0][x - 4] == map[0][x - 2] \
		|| map[0][x - 3] == map[0][x - 2])
			return (0);
		if (check_chars_in_line(map, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

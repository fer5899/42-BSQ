/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:25:17 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/08 12:22:11 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

void	put_str(char *str)
{
	if (*str != '\0')
	{
		write(1, str, 1);
		put_str(str + 1);
	}
}

int	str_len(char *str)
{
	int	char_count;

	char_count = 0;
	while (*str != '\0')
	{
		char_count++;
		str++;
	}
	return (char_count);
}

void	print_map(char **map, int n_rows)
{
	int	row;

	row = 1;
	while (row < n_rows)
	{
		put_str(map[row]);
		write(1, "\n", 1);
		row++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:25:17 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/07 14:31:09 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	if (*str != '\0')
	{
		write(1, str, 1);
		ft_putstr(str + 1);
	}
}

int	strlen(char *str)
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

	row = 0;
	while (row < n_rows)
	{
		putstr(map[row]);
		write(1, "\n", 1);
	}
}

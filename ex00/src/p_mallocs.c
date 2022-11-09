/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_mallocs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:05:23 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/09 12:32:11 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

char	*c_malloc(int size)
{
	char	*ptr;

	ptr = (char *) malloc(sizeof(char) * size);
	if (ptr == NULL)
		exit(2);
	return (ptr);
}

char	**cc_malloc(int size)
{
	char	**ptr;

	ptr = (char **) malloc(sizeof(char *) * size);
	if (ptr == NULL)
		exit(2);
	return (ptr);
}

t_point	*pt_malloc(int size)
{
	t_point	*ptr;

	ptr = (t_point *) malloc(sizeof(t_point) * size);
	if (ptr == NULL)
		exit(2);
	return (ptr);
}

void	free_map(char **map, int n_rows)
{
	int	row;

	row = 0;
	while (row < n_rows)
	{
		free(map[row]);
		row++;
	}
	free(map);
}

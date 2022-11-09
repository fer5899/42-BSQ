/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramos-l <bramos-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:22:39 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/09 09:22:41 by bramos-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"

int	count_line_jumps(char *str)
{
	int	aux;
	int	count;

	count = 0;
	aux = 0;
	while (str[aux] != '\0')
	{
		if (str[aux] == '\n')
			count++;
		aux++;
	}
	return (count);
}

char	*rewrite_for_error(char *str)
{	
	free(str);
	str = c_malloc(3);
	str[0] = 'x';
	str[1] = '\n';
	return (str);
}

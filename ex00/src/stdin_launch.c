/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_launch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:08:41 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/09 11:25:41 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers.h"
#include <stdio.h>

unsigned int    strl_cpy(char *dest, char *src, unsigned int size)
{
    unsigned int    count;
    int             in_size;
    count = 0;
    in_size = str_len(src);
    if (size > 0)
    {
        while (count < (size - 1))
        {
            *dest = *src;
            src++;
            dest++;
            count++;
        }
        *dest = '\0';
    }
    return (in_size);
}

char	*read_stdin()
{
	char	ch;
	char	*stdin_rst;
	char	*stdin_aux;
	int		aux;

	aux = 1;
	stdin_rst = c_malloc(1);
	stdin_aux = c_malloc(1);
	while(read(0, &ch, 1) > 0 && ch != 27)
	{
		free(stdin_aux);
		stdin_aux = c_malloc(aux + 1);
		if (stdin_aux == NULL)
			exit(1);
		strl_cpy(stdin_aux, stdin_rst, aux + 1);
		free(stdin_rst);
		stdin_rst = c_malloc(aux + 1);
		strl_cpy(stdin_rst, stdin_aux, aux + 1);
		stdin_rst[aux - 1] = ch;
		aux++;
	}
	return (stdin_rst);
}

void	stdin_launch(void)
{
	char		*stdin_map;
	t_square	bsq;
	char		**map;
	int			n_rows;
	
	stdin_map = read_stdin();
	printf("%s", stdin_map);
	n_rows = 0;
	map = get_map_stdin(stdin_map, &n_rows);
	if (check_map(map, n_rows) == 0)
		write(1, "map error\n", 11);
	else
	{
		bsq = p_find_bsq(map, n_rows, extract_obstacles(map, n_rows));
		if (bsq.ep.row != -1)
			insert_bsq(map, n_rows, bsq);
		print_map(map, n_rows);
	}
}
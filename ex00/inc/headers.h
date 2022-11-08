/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:02:12 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/08 12:07:55 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_point {
	int	row;
	int	col;
}	t_point;

typedef struct s_square {
	t_point	sp;
	t_point	ep;
}	t_square;

int		str_cmp(char *s1, char *s2);

int		a_to_i(char *numb);

int		info_rows(char *info);

int		check_map(char **map, int row_number);

int		count_obstacles(char **map, int n_rows);

t_point	*extract_obstacles(char **map, int n_rows, int *n_obs);

char	*map_to_string(char *namefile);

int		row_number(char *str);

int		col_number(char *str);

char	**get_map(char *namefile, int *n_rows);

char	**insert_bsq(char **map, int n_rows, t_square bsq);

void	put_str(char *str);

int		str_len(char *str);

void	print_map(char **map, int n_rows);

#endif
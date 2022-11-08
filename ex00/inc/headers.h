/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:02:12 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/08 23:11:43 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

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

int			str_cmp(char *s1, char *s2);

int			a_to_i(char *numb);

int			info_rows(char *info);

int			check_chars_in_line(char **map, int i);

int			check_map(char **map, int row_number);

int			count_obstacles(char **map, int n_rows);

t_point		*extract_obstacles(char **map, int n_rows);

char		*map_to_string(char *namefile);

int			row_number(char *str);

int			col_number(char *str);

char		**get_map(char *namefile, int *n_rows);

char		**insert_bsq(char **map, int n_rows, t_square bsq);

int			obs_arr_len(t_point *obs_arr);

void		put_str(char *str);

int			str_len(char *str);

void		print_map(char **map, int n_rows);

t_point		init_pt(int row, int col);

t_square	init_sq(t_point sp, t_point ep);

int			sq_is_valid(t_square bsq, t_point *obs_arr);

t_square	compare_squares(t_square bsq, t_square next_bsq);

t_square	get_start_sq(int n_rows, int n_cols, t_point sp);

int			sq_size(t_square sq);

char		**get_map_stdin(char *ol_map, int *n_rows);

t_square	rec_find_bsq(t_square sq, t_square minsq, t_point *obs_arr);

t_square	find_bsq(char **map, int n_rows, t_point *obs_arr);

t_point		*create_obs_arr(char **map, int n_rows);

char		*c_malloc(int size);

char		**cc_malloc(int size);

t_point		*pt_malloc(int size);

#endif
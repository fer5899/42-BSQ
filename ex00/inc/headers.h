/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:02:12 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/09 13:03:24 by fgomez-d         ###   ########.fr       */
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
}	t_pt;

typedef struct s_square {
	t_pt	sp;
	t_pt	ep;
}	t_sq;

int				str_cmp(char *s1, char *s2);

int				a_to_i(char *numb);

int				info_rows(char *info);

int				check_chars_in_line(char **map, int i);

int				check_map(char **map, int row_number);

int				count_obstacles(char **map, int n_rows);

t_pt			*extract_obstacles(char **map, int n_rows);

char			*map_to_string(char *namefile);

int				row_number(char *str);

int				col_number(char *str);

int				count_line_jumps(char *str);

char			*rewrite_for_error(char *str);

char			**get_map(char *namefile, int *n_rows);

char			**insert_bsq(char **map, int n_rows, t_sq bsq);

int				obs_arr_len(t_pt *obs_arr);

void			put_str(char *str);

int				str_len(char *str);

void			stdin_launch(void);

char			*read_stdin(char *stdin_map);

unsigned int	strl_cpy(char *dest, char *src, unsigned int size);

void			print_map(char **map, int n_rows);

t_pt			init_pt(int row, int col);

t_sq			init_sq(t_pt sp, t_pt ep);

int				sq_is_valid(t_sq bsq, t_pt *obs_arr);

t_sq			compare_squares(t_sq bsq, t_sq next_bsq);

t_sq			get_start_sq(int n_rows, int n_cols, t_pt sp);

char			**get_map_stdin(char *ol_map, int *n_rows);

t_sq			rec_find_bsq(t_sq sq, t_sq minsq, t_pt *obs_arr);

t_sq			ind_bsq(char **map, int n_rows, t_pt *obs_arr);

t_pt			*create_obs_arr(char **map, int n_rows);

char			*c_malloc(int size);

char			**cc_malloc(int size);

t_pt			*pt_malloc(int size);

t_sq			get_bsq(t_sq ssq, t_sq bsq, t_sq *nsq, t_pt *oarr);

t_sq			p_find_bsq(char **map, int n_rows, t_pt *obs_arr);

t_sq			find_bsq(char **map, int n_rows, t_pt *obs_arr);

void			free_map(char **map, int n_rows);


#endif
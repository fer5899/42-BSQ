/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:14:28 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/07 17:06:30 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*map_to_string(char *namefile);

int		row_number(char *str);

int		col_number(char *str);

char	**get_map(char *namefile, int *n_rows);

#endif

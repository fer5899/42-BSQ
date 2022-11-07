/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramos-l <bramos-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:14:28 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/07 16:14:29 by bramos-l         ###   ########.fr       */
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

char	**map_to_2d(char *namefile);

#endif

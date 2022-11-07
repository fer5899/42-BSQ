/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_obstacles.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:04:01 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/07 18:07:24 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRACT_OBSTACLES_H
# define EXTRACT_OBSTACLES_H

# include <stdlib.h>
# include "print_map.h"
# include "structs.h"

int		count_obstacles(char **map, int n_rows);

t_obs	*extract_obstacles(char **map, int n_rows, int *n_obs);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramos-l <bramos-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:59:48 by bramos-l          #+#    #+#             */
/*   Updated: 2022/11/07 21:59:50 by bramos-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

#include "../inc/print_map.h"

#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2);

int	a_to_i(char *numb);

int	info_rows(char *info);

int	check_map(char **map, int row_number);

#endif
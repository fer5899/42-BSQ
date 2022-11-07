/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:25:17 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/07 17:17:25 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MAP_H
# define PRINT_MAP_H

# include <unistd.h>

void	put_str(char *str);

int		str_len(char *str);

void	print_map(char **map, int n_rows);

#endif
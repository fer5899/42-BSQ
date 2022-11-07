/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bsq.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:59:05 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/07 19:23:06 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BSQ_H
# define DRAW_BSQ_H

# include "../inc/structs.h"
# include "../inc/print_map.h"

char	**draw_bsq(char **map, int n_rows, t_square bsq);

#endif
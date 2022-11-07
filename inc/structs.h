/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:06:53 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/11/07 19:06:27 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_obs {
	int	row;
	int	col;
}	t_obs;

typedef struct s_square {
	int	sp_row;
	int	sp_col;
	int	ep_row;
	int	ep_col;
}	t_square;

#endif
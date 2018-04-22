/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:01:19 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/22 19:23:26 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>
# include "parser.h"

typedef struct 	s_env
{
	char		player_letter;
	t_uint8		plateau_x;
	t_uint8		plateau_y;
	t_string	plateau_data;
	t_string	plateau_data_test;
	t_uint8		piece_x;
	t_uint8		piece_y;
	t_uint8		piece_offset[NB_PIECE_OFFSET];
	t_uint8		piece_offset_size;
	t_uint8		analyse_x;
	t_uint8		analyse_y;
}				t_env;

void	init(t_env *e);

#endif

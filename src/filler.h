/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:01:19 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/23 17:36:43 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>
# define STDIN_FILENO		0
# define KEYWORD_1_1		"$$$ exec p1"
# define KEYWORD_1_2		"$$$ exec p2"
# define NB_PIECE_OFFSET	100
# define OFFSET_JUMP		10
# define PATH_DEBUG			"pierre.log"
#include <stdio.h>
extern FILE *fd;

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

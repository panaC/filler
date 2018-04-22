/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:07:43 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/22 19:35:35 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "filler.h"
# define STDIN_FILENO		0
# define KEYWORD_1_1		"$$$ exec p1"
# define KEYWORD_1_2		"$$$ exec p2"
# define NB_PIECE_OFFSET	100
# define OFFSET_JUMP		10 + 1

int		parser(t_env *e, t_string *l);
int		parser_player(t_env *e, t_string l);
int		parser_plateau(t_env *e, t_string l);
int		parser_piece(t_env *e, t_string l);
int		parser_piece_shape(t_env *e, t_string l, t_uint8 j);

#endif

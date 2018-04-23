/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:07:43 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/23 15:12:48 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "filler.h"

int		parser(t_env *e, t_string l);
int		parser_player(t_env *e, t_string l);
int		parser_plateau(t_env *e, t_string l);
int		parser_piece(t_env *e, t_string l);
int		parser_piece_shape(t_env *e, t_string l, t_uint8 j);

#endif

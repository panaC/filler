/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:08:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/22 19:55:45 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "parser.h"

int		parser(t_env *e, t_string *l)
{
	static int		i = 0;

	printf("parser i %d\n", i);
	if (i == 3)
		i = 4;
	if (i == 0)
		i = parser_player(e, l);
	else if (i == 1)
		i = parser_plateau(e, l);
	else if (i == 2)
		i = parser_piece(r, l);
	else if (i == 4)
		i = 1;
	return (i)
}

int		parser_player(t_env *e, t_string l)
{
	if (ft_strncmp(l, KEYWORD_1_1, ft_strlen(KEYWORD_1_1)))
		e->player_letter = 'O';
	else if (ft_strncmp(l, KEYWORD_1_1, ft_strlen(KEYWORD_1_2)))
		e->player_letter = 'X';
	else
		return (0);
	return (1);
}

int		parser_plateau(t_env *e, t_string l)
{
	static int		i = 0;

	printf("parser_plateau i %d\n", i);
	if (i == 0)
	{
		l = ft_strchr(l, ' ')
		e->plateau_y = ft_atoi(l);
		e->plateau_x = ft_atoi(ft_strchr(l, ' '));
		if ((e->plateau_x != 0 && e->plateau_y != 0) && !(e->plateau_data =
					ft_strnew((e->plateau_x + 1) * e->plateau_y + 1)))
			return (0);
	}
	if (i > 1 && ft_strlen(l) > 4)
		ft_strncpy(e->plateau_data + ((i - 2) * (e->plateau_x + 1)),
				l + 4, (size_t)e->plateau_x);
	else if (i > 1)
		return (0);
	if (i == e->plateau_y + 1 && (i = 1))
		return (2);
	++i;
	return (1);
}

int		parser_piece(t_env *e, t_string l)
{
	static int			i = 0;
	static t_uint8		j = 0;

	printf("parser_piece i %d\n", i);
	if (i == 0)
	{
		l = ft_strchr(l, ' ')
		e->piece_y = ft_atoi(l);
		e->piece_x = ft_atoi(ft_strchr(l, ' '));
		if ((e->piece_x != 0 && e->piece_y != 0))
			return (0);
	}
	else if (ft_strchr(l, '*') != NULL)
		j = parser_piece_shape(e, l, j);
	if (i == e->piece_y)
	{
		e->piece_offset_size = j;
		i = 0;
		j = 0;
		return (3);
	}
	++i;
	return (2);
}

int		parser_piece_shape(t_env *e, t_string l, t_uint8 j)
{
	t_string		ptr;
	t_string		star;

	printf("parser_piece_shape i %d\n", i);
	ptr = l;
	while ((star = ft_strchr(ptr, '*')) && j < NB_PIECE_OFFSET)
	{
		e->piece_offset[j] = star - ptr;
		ptr = star;
		++j;
	}
	e->piece_offset[j] = ft_strchr(ptr, '\n') - ptr + OFFSET_JUMP;
	return (j);
}
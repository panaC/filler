/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:08:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/25 15:49:54 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "parser.h"

int		parser(t_env *e, t_string l)
{
	static int		i = 0;

	fprintf(fd, "parser i %d\n", i);
	if (i == 3)
		i = 4;
	if (i == 0)
		i = parser_player(e, l);
	else if (i == 1)
		i = parser_plateau(e, l);
	else if (i == 2)
		i = parser_piece(e, l);
	else if (i == 4)
		i = 1;
	return (i);
}

int		parser_player(t_env *e, t_string l)
{
	if (ft_strncmp(l, KEYWORD_1_1, ft_strlen(KEYWORD_1_1)) == 0)
	{
		e->player_letter = 'O';
		e->ads_letter = 'X';
	}
	else if (ft_strncmp(l, KEYWORD_1_2, ft_strlen(KEYWORD_1_2)) == 0)
	{
		e->player_letter = 'X';
		e->ads_letter = 'O';
	}
	else
		return (0);
	return (1);
}

int		parser_plateau(t_env *e, t_string l)
{
	static int		i = 0;

	fprintf(fd, "parser_plateau i %d\n", i);
	if (i == 0)
	{
		l = ft_strchr(l, ' ');
		e->plateau_y = ft_atoi(l);
		e->plateau_x = ft_atoi(ft_strchr(l + 1, ' '));
		if ((e->plateau_x != 0 && e->plateau_y != 0) && !(e->plateau_data =
					ft_strnew(e->plateau_x * e->plateau_y + 1)))
			return (0);
	}
	if (i > 1 && ft_strlen(l) == (4 + e->plateau_x))
		ft_strncpy(e->plateau_data + ((i - 2) * e->plateau_x),
				l + 4, (size_t)e->plateau_x);
	else if (i > 1)
		return (0);
	if (i == e->plateau_y + 1 && (i = 1))
	{
		fprintf(fd, "x %d y %d\n%s\n", e->plateau_x, e->plateau_y, e->plateau_data);
		return (2);
	}
	++i;
	return (1);
}

int		parser_piece(t_env *e, t_string l)
{
	static int			i = 0;
	static t_uint8		j = 0;

	fprintf(fd,"parser_piece i %d\n", i);
	if (i == 0)
	{
		l = ft_strchr(l, ' ');
		e->piece_y = ft_atoi(l);
		e->piece_x = ft_atoi(ft_strchr(l + 1, ' '));
		if ((e->piece_x == 0 || e->piece_y == 0))
			return (0);
		ft_bzero(e->piece_offset, NB_PIECE_OFFSET);
		e->piece_pixel_bool = FALSE;
	}
	else if (ft_strchr(l, '*') != NULL)
		j = parser_piece_shape(e, l, j);
	else
		e->piece_offset[j] += OFFSET_JUMP;
	if (i == e->piece_y)
	{
		fprintf(fd, "x %d y %d\n", e->piece_x, e->piece_y);
		e->piece_offset_size = j;
		i = 0;
		j = 0;
		int t = 0;
		while (t <= e->piece_offset_size)
			fprintf(fd, "%d ", e->piece_offset[t++]);
		fprintf(fd, "\n");
		return (3);
	}
	++i;
	return (2);
}

int		parser_piece_shape(t_env *e, t_string l, t_uint8 j)
{
	t_string		ptr;
	t_string		star;

	fprintf(fd,"parser_piece_shape j %d\n", j);
	ptr = l;
	while ((star = ft_strchr(ptr, '*')) && j < NB_PIECE_OFFSET)
	{
		e->piece_offset[j] += (star - ptr);
		fprintf(fd, "j %d e->piece_offset %d\n", j , e->piece_offset[j]);
		ptr = star + 1;
		++j;
		e->piece_offset[j] = 1;
	}
	e->piece_offset[j] = OFFSET_JUMP;
	fprintf(fd, "j %d e->piece_offset %d\n", j , e->piece_offset[j]);

	return (j);
}

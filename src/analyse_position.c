/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 01:59:52 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/29 02:00:37 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "filler.h"
#include "analyse.h"

t_bool			analyse_check_position(t_env *e, t_uint32 pos)
{
	e->start_pc_pl = pos % e->plateau_x;
	e->num_line = pos / e->plateau_x;
	e->piece_pixel_bool = FALSE;
	if (e->num_line + e->piece_y > e->plateau_y ||
			e->start_pc_pl + e->piece_x > e->plateau_x)
		return (FALSE);
	if (analyse_check_position_while(e, pos, e->piece_offset[0]) == FALSE)
		return (FALSE);
	if (e->piece_pixel_bool == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool			analyse_check_position_while(t_env *e, t_uint32 pos,
		t_uint32 piece_offset)
{
	int			i;

	i = 0;
	while (i < e->piece_offset_size)
	{
		piece_offset = e->piece_offset[i];
		while (piece_offset >= 100)
		{
			e->num_line++;
			pos = e->plateau_x * e->num_line + e->start_pc_pl;
			piece_offset -= 100;
		}
		pos += piece_offset;
		if (e->plateau_data[pos] == e->player_letter)
		{
			if (e->piece_pixel_bool == FALSE)
				e->piece_pixel_bool = TRUE;
			else
				return (FALSE);
		}
		else if (e->plateau_data[pos] == e->ads_letter)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

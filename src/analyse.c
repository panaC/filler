/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:00:13 by pierre            #+#    #+#             */
/*   Updated: 2018/04/25 21:56:55 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include "filler.h"
#include "analyse.h"

int			analyse(t_env *e)
{
	analyse_algo_brut(e);
	return ((e->analyse_pos == -1 ) ? 0 : 1);
}

void		analyse_algo_brut(t_env *e)
{
	int				i;
	int 			j;
	static int		status = 0;
	static t_uint8	sign = 0;

	if (status == 0)
	{
		status = 1;
		i = e->plateau_x * e->plateau_y - 1;
		while(i >= 0)
		{
			if (analyse_check_position(e, i))
			{
				e->analyse_pos = i;
				return;
			}
			i--;
		}
	}
	else if (status == 1)
	{
		status = 2;
		i = 0;
		while(i < e->plateau_x * e->plateau_y - 1)
		{
			if (analyse_check_position(e, i))
			{
				e->analyse_pos = i;
				return;
			}
			i++;
		}
	}
	else if (status == 2)
	{
		status = 0;
		j = 0;
		i = (e->plateau_x * e->plateau_y - 1) / 2;
		while(j <= e->plateau_x * e->plateau_y)
		{
			sign ^= 1;
			j++;
			if (analyse_check_position(e, i))
			{
				e->analyse_pos = i;
				return;
			}
			if (sign == 0)
				i -= j;
			else
				i += j;
		}
	}
	e->analyse_pos = -1;
}

t_bool		analyse_check_position(t_env *e, t_uint32 pos)
{
	int			i;
	int			start_pc_pl;
	t_uint8		num_line;
	t_bool		piece_pixel_bool;
	t_uint32	piece_offset;

	fprintf(fd, "PIECE\n");
		int t = 0;
		while (t <= e->piece_offset_size)
			fprintf(fd, "%d ", e->piece_offset[t++]);
		fprintf(fd, "\n");

	fprintf(fd, "PIECE\n");

	i = 0;
	start_pc_pl = pos % e->plateau_x;
	num_line = pos / e->plateau_x;
	piece_pixel_bool = FALSE;
	fprintf(fd, "START -> start_pc_pl %d num_line %d emplacement %d piece_pixel_bool %d\n", start_pc_pl, num_line, pos % e->plateau_x,
			piece_pixel_bool);
	if (num_line + e->piece_y > e->plateau_y ||
			start_pc_pl + e->piece_x > e->plateau_x)
	{
		fprintf(fd, "PIECE HORS PLATEAU RETURN FALSE\n");
		return (FALSE);
	}
	while (i < e->piece_offset_size)
	{
		piece_offset = e->piece_offset[i];
		fprintf(fd, "i %d e->piece_offset[i] %d\n", i, e->piece_offset[i]);
		while (piece_offset >= 100)
		{
			num_line++;
			pos = e->plateau_x * num_line + start_pc_pl;
			piece_offset -= 100;
		}
		pos += piece_offset;
		fprintf(fd, "ENTER POSITION\n");
		fprintf(fd, "start_pc_pl %d num_line %d emplacement %d pos %d piece_pixel_bool %d\n", start_pc_pl, num_line, pos % e->plateau_x, pos, piece_pixel_bool);
		if (e->plateau_data[pos] == e->player_letter)
		{
			if (piece_pixel_bool == FALSE)
			{
				fprintf(fd, "bool pixel TRUE\n");
				piece_pixel_bool = TRUE;
			}
			else
			{
				fprintf(fd, "bool pixel IS SET RETURN FALSE\n");
				return (FALSE);
			}
		}
		else if (e->plateau_data[pos] == e->ads_letter)
		{
			fprintf(fd, "POSITION ADVERSAIRE RETURN FALSE\n");
			return (FALSE);
		}
		i++;
	}
	if (piece_pixel_bool == TRUE)
	{

		fprintf(fd, "END WHILE bool pixel TRUE : RETURN\n");
		return (TRUE);
	}
	fprintf(fd, "RETURN FALSE FUNCTION\n");
	return (FALSE);
}

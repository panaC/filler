/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:00:13 by pierre            #+#    #+#             */
/*   Updated: 2018/04/28 22:10:48 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include "filler.h"
#include "analyse.h"

int			analyse(t_env *e)
{
	int			i;
	int			j;
	int			i_max;
	static int	status = 0;
	static int	sign = 0;
	t_uint32	distance_old;
	t_uint32	board;

	i = 0;
	board = e->plateau_y * e->plateau_x;
	j = (e->plateau_x * e->plateau_y - 1) / 2;
	i_max = e->plateau_x * e->plateau_y;
	e->analyse_pos = -1;
	distance_old = 0xFFFFFF;
	if (status == 1)
	{
		i = e->plateau_x * e->plateau_y - 1;
		i_max = 0;
	}
	while (i != i_max)
	{
		if (analyse_check_position(e, i))
		{
			if (board < 1600)
				distance_old = analyse_follow_him(e, i, distance_old);
			else
				e->analyse_pos = i;
		}
		if (status == 0)
			i++;
		else if (status == 1)
			i--;
		else
		{
			i++;
			sign ^= 1;
			if (sign == 0)
				j -= i;
			else
				j += i;
		}
	}
	status++;
	if (status == 3)
		status = 0;
	return ((e->analyse_pos == -1 ) ? 0 : 1);
}

t_uint32	analyse_follow_him(t_env *e, t_uint32 i, t_uint32 dis_old)
{
	t_uint32	distance;
	t_string	ptr;

	ptr = e->plateau_data;
	while ((ptr = ft_strchr(ptr, e->ads_letter)))
	{
		distance = 0;
		distance = ((ft_abs(i % e->plateau_x -
					(e->plateau_x * e->plateau_y / 2) % e->plateau_x) +
				ft_abs(i / e->plateau_y -
					(e->plateau_x * e->plateau_y / 2) / e->plateau_y)) ==
				(e->plateau_x * e->plateau_y / 2)) ? 0 : 1;
		distance += (ft_abs(i % e->plateau_x - (ptr - e->plateau_data) %
				e->plateau_x) + ft_abs(i / e->plateau_y -
					(ptr - e->plateau_data) / e->plateau_y));
		if (distance < dis_old)
		{
			e->analyse_pos = i;
			dis_old = distance;
		}
		ptr++;
	}
	return (dis_old);
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

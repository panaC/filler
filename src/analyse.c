/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:00:13 by pierre            #+#    #+#             */
/*   Updated: 2018/04/29 02:03:07 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "filler.h"
#include "analyse.h"

int				analyse(t_env *e)
{
	int			i;
	int			i_max;
	static int	status = 0;

	i = 0;
	i_max = e->plateau_x * e->plateau_y;
	e->analyse_pos = -1;
	status++;
	if (status == 3)
		status = 0;
	if (status == 1 || status == 2)
		i = (e->plateau_x * e->plateau_y - 1) / status;
	if (status == 1)
		i_max = 0;
	analyse_while(e, i, i_max, status);
	return ((e->analyse_pos == -1) ? 0 : 1);
}

void			analyse_while(t_env *e, int i, int i_max, int status)
{
	int			j;
	int			sign;
	t_uint32	board;
	t_uint32	distance_old;

	j = 0;
	sign = 0;
	board = e->plateau_y * e->plateau_x;
	distance_old = 0xFFFFFF;
	while (i != i_max)
	{
		if (analyse_check_position(e, i))
		{
			if (board < 1600)
				distance_old = analyse_follow_him(e, i, distance_old);
			else
			{
				e->analyse_pos = i;
				return ;
			}
		}
		analyse_while_if(status, &i, &j, &sign);
	}
}

void			analyse_while_if(int status, int *i, int *j, int *sign)
{
	if (status == 0)
		(*i)++;
	else if (status == 1)
		(*i)--;
	else
	{
		(*j)++;
		*sign ^= 1;
		if (*sign == 0)
			*i -= *j;
		else
			*i += *j;
	}
}

t_uint32		analyse_follow_him(t_env *e, t_uint32 i, t_uint32 dis_old)
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

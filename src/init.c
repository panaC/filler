/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:04:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/23 20:17:19 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "filler.h"

void	init(t_env *e)
{
	e->player_letter = 'X';
	e->plateau_x = 0;
	e->plateau_y = 0;
	e->plateau_data = NULL;
	e->plateau_data_test = NULL;
	e->piece_x = 0;
	e->piece_y = 0;
	ft_bzero(e->piece_offset, NB_PIECE_OFFSET);
	e->piece_offset_size = 0;
	e->analyse_x = 0;
	e->analyse_y = 0;
}

void	print(t_env *e)
{
	DEBUG("%d %d\n", e->analyse_y, e->analyse_x);
	ft_putnbr(e->analyse_y);
	ft_putchar(' ');
	ft_putnbr(e->analyse_x);
	ft_putchar('\n');
}

void	get_start_position(t_env *e)
{
	int			pos;
	t_string	ptr;

	if ((ptr = ft_strchr(e->plateau_data, e->player_letter)))
	{
		DEBUG("%d %d\n", e->analyse_y_start, e->analyse_x_start);
		pos = ptr - e->plateau_data;
		e->analyse_y_start = pos / e->plateau_x;
		e->analyse_x_start = pos % e->plateau_x;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:04:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/29 01:37:23 by pleroux          ###   ########.fr       */
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
	e->piece_x = 0;
	e->piece_y = 0;
	ft_bzero(e->piece_offset, NB_PIECE_OFFSET);
	e->piece_offset_size = 0;
	e->analyse_x = 0;
	e->analyse_y = 0;
	e->analyse_pos = 0;
	e->start_pc_pl = 0;
	e->num_line = 0;
	e->piece_pixel_bool = FALSE;
}

void	print(t_env *e)
{
	ft_putnbr(e->analyse_pos / e->plateau_x);
	ft_putchar(' ');
	ft_putnbr(e->analyse_pos % e->plateau_x);
	ft_putchar('\n');
}

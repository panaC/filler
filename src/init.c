/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:04:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/22 20:44:19 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "filler.h"

void	init(t_env *e)
{
	e->player_letter = 'X';
	e->plateau_x = 0;
	e->plateau_y = 0;
	e->plateau_state = 0;
	e->piece_state = 0;
}

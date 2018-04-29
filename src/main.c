/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:32:55 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/29 02:09:38 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include "filler.h"
#include "parser.h"
#include "analyse.h"

int		main(void)
{
	t_env		e;
	t_uint8		res;
	t_string	line;

	init(&e);
	while (1)
	{
		if (get_next_line(STDIN_FILENO, &line))
		{
			res = parser(&e, line);
			free(line);
			if (res == 0)
				break ;
			else if (res == 3)
			{
				if (analyse(&e))
					print(&e);
				else
					break ;
			}
		}
	}
	ft_putstr("0 0\n");
	ft_memdel((void**)&(e.plateau_data));
	return (0);
}

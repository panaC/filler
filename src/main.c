/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:32:55 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/22 19:43:03 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include "filler.h"
#include "parser.h"

int		main(void)
{
	t_env		*e;
	t_uint8		res;
	t_string	line

	i = 0;
	init(e);
	while (1)
	{
		if (get_next_line(STDIN_FILENO, &line))
		{
			res = parser(e, line);
			printf("res %d\n", res);
			/*
			if (res == 0)
				//erreur parsing & quit
			free(line);
			if (res == 3)
			{
				if (analyse(e))
					print_res()
			}
			//ne pas oublier de free le plateau
			*/
		}
	}
	ft_putstr("EOF\n");
}

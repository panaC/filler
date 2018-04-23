/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:32:55 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/23 17:20:33 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include "filler.h"
#include "parser.h"
#include <stdio.h>

FILE *fd;

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
			fd = fopen(PATH_DEBUG, "a");
			fprintf(fd, "#%s#\n", line);
			res = parser(&e, line);
			fprintf(fd, "res %d\n", res);
			free(line);
			if (res == 0)
			{
				//erreur parsing & quit
				fprintf(fd, "QUIT\n");
				return (0);
			}
			else if (res == 3)
			{
				ft_putstr("12 13\n");
				fprintf(fd, "12 14\n");
				//if (analyse(&e))
				//	print_res(&e)
			}
			//ne pas oublier de free le plateau
			fclose(fd);
		}
	}
}

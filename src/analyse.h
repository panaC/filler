/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:18:54 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/25 17:58:08 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSE_H
# define ANALYSE_H
# include "filler.h"

int			analyse(t_env *e);
void		analyse_algo_brut(t_env *e);
t_bool		analyse_check_position(t_env *e, t_uint32 pos);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:18:54 by pleroux           #+#    #+#             */
/*   Updated: 2018/04/28 20:43:24 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSE_H
# define ANALYSE_H
# include "filler.h"

int			analyse(t_env *e);
void		analyse_algo_brut(t_env *e);
t_bool		analyse_check_position(t_env *e, t_uint32 pos);
t_uint32	analyse_follow_him(t_env *e, t_uint32 i, t_uint32 dis_old);


#endif

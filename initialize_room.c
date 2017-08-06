/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 05:48:09 by twalton           #+#    #+#             */
/*   Updated: 2017/07/25 05:48:09 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	initialize_room(t_room *basic, t_dataroom *complex, int type)
{
	if (!basic)
	{
		complex->name = NULL;
		return ;
	}
	complex->type = type;
	complex->name = basic->name;
	complex->dfs = -1;
	if (type == 2)
		complex->dfs = 0;
	complex->links = NULL;
	complex->dists = NULL;
}

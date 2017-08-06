/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_previous_room.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 21:02:30 by twalton           #+#    #+#             */
/*   Updated: 2017/08/02 21:02:30 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_dataroom	*go_to_previous_room(t_dataroom *room)
{
	int i;

	i = 0;
	while (room->dfs - room->links[i]->dfs <  room->dists[i] - 0.0001 ||
	room->dfs - room->links[i]->dfs > room->dists[i] + 0.0001)
	{
		++i;
	}
	return (room->links[i]);
}

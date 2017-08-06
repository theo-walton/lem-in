/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_info_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:52:08 by twalton           #+#    #+#             */
/*   Updated: 2017/07/24 23:52:08 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_dataroom	*convert_info_to_map(t_info *info)
{
	int i;
	t_dataroom *room;

	i = 0;
	if (!(room = malloc(sizeof(t_dataroom) * 10000)))
		return (NULL);
	initialize_room(&(info->start), &(room[0]), 2);
	initialize_room(&(info->end), &(room[1]), 3);
	while ((info->rooms)[i].name)
	{
		initialize_room(&(info->rooms[i]), &(room[i + 2]), 1);
		++i;
	}
	initialize_room(NULL, &(room[i + 2]), 0);
	i = 0;
	while (room[i].name)
	{
		add_link_data(&room[i], room, info);
		++i;
	}
	return (room);
}

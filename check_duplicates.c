/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 23:01:59 by twalton           #+#    #+#             */
/*   Updated: 2017/07/23 23:01:59 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int	compare_room(t_room room, t_info *info)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while ((info->rooms)[i].name)
	{
		if (!ft_strcmp(room.name, (info->rooms)[i].name))
			++counter;
		++i;
	}
	if (!ft_strcmp(room.name, info->start.name))
		++counter;
	if (!ft_strcmp(room.name, info->end.name))
		++counter;
	if (counter == 1)
		return (0);
	return (1);
}

static int      coor_check(t_room room1, t_room room2)
{
	if (room1.x == room2.x && room1.y == room2.y)
		return (1);
	return (0);
}

static int	compare_coor(t_room room, t_info *info)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while ((info->rooms)[i].name)
	{
		if (!coor_check(room, (info->rooms)[i]))
			++counter;
		++i;
	}
	if (!coor_check(room, info->start))
		++counter;
	if (!coor_check(room, info->end))
		++counter;
	if (counter != 1)
		return (0);
	return (1);
}

int	check_duplicates(t_info *info)
{
	int i;

	i = 0;
	if (compare_room(info->start, info))
		return (0);
	if (compare_room(info->end, info))
		return (0);
	while ((info->rooms)[i].name)
		if (compare_room((info->rooms)[i++], info))
			return (0);
	if (compare_coor(info->start, info))
		return (0);
	if (compare_coor(info->end, info))
		return (0);
	while ((info->rooms)[i].name)
		if (compare_coor((info->rooms)[i++], info))
			return (0);
	return (1);
}

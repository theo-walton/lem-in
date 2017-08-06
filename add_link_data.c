/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 05:55:49 by twalton           #+#    #+#             */
/*   Updated: 2017/07/25 05:55:49 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static char	*get_other_room_name(t_link *link, char *room_name)
{
	if (!ft_strcmp(link->r1, room_name))
		return (link->r2);
	if (!ft_strcmp(link->r2, room_name))
		return (link->r1);
	return (NULL);
}

static t_dataroom	*find_room(char *room_name, t_dataroom *rarr)
{
	int i;

	i = -1;
	while (rarr[++i].name)
	{
		if (!ft_strcmp(room_name, rarr[i].name))
			return (&rarr[i]);
	}
	return (NULL);
}

static int	total_links(char *room_name, t_link *link)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (link[i].r1)
	{
		if (!ft_strcmp(room_name, link[i].r1))
			++ret;
		else if (!ft_strcmp(room_name, link[i].r2))
			++ret;
		++i;
	}
	return (ret);
}

static int	initialize_link_info(int i, t_dataroom *room)
{
	if (!(room->links = malloc(sizeof(t_dataroom*) * i)))
		return (0);
	if (!(room->dists = malloc(sizeof(double) * i)))
	{
		free(room->links);
		return (0);
	}
	return (1);
}

int	add_link_data(t_dataroom *room, t_dataroom *rarr, t_info *info)
{
	int i;
	char *str;
	t_dataroom *p;
	int k;

	i = total_links(room->name, info->links);
	if (!initialize_link_info(i, room))
		return (0);
	room->links[i - 1] = NULL;
	room->dists[i - 1] = -1;
	i = -1;
	k = 0;
	while (info->links[++i].r1)
	{
		if (get_other_room_name(&info->links[i], room->name))
		{
			str = get_other_room_name(&info->links[i], room->name);
			p = find_room(str, rarr);
			room->links[k] = p;
			room->dists[k] = get_rooms_dist(&info->links[i], info);
			++k;
		}
	}
	return (1);
}

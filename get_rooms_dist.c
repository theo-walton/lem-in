/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 00:29:50 by twalton           #+#    #+#             */
/*   Updated: 2017/08/02 00:29:50 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static t_room	*find_basic_room(char *room_name, t_info *info)
{
	int i;

	i = 0;
	while (info->rooms[i].name)
	{
		if (!ft_strcmp(room_name, info->rooms[i].name))
			return (&info->rooms[i]);
		++i;
	}
	if (!ft_strcmp(room_name, info->start.name))
		return (&info->start);
	if (!ft_strcmp(room_name, info->end.name))
		return (&info->end);
	return (NULL);
}

static double	root(double x)
{
	double a;
	double b;
	double c;
	double d;

	a = 1;
	d = -1;
	while (a * a < x)
		a = a * 2;
	if (a == 1)
		b = 0;
	else
		b = a / 2;
	c = (a + b) / 2;
	while (c != d)
	{
		d = c;
		if (c * c > x)
			a = c;
		else
			b = c;
		c = (a + b) / 2;
	}
	return (c);
}

static double	pythag(unsigned int xdif, unsigned int ydif)
{
	double a;
	double b;

	a = (double)xdif;
	b = (double)ydif;
	return (root(a * a + b * b));
}

double	get_rooms_dist(t_link *link, t_info *info)
{
	t_room *rooms[2];
	unsigned int xdif;
	unsigned int ydif;

	rooms[0] = find_basic_room(link->r1, info);
	rooms[1] = find_basic_room(link->r2, info);
	if (rooms[0]->x > rooms[1]->x)
		xdif = rooms[0]->x - rooms[1]->x;
	else
		xdif = rooms[1]->x - rooms[0]->x;
	if (rooms[0]->y > rooms[1]->y)
		ydif = rooms[0]->y - rooms[1]->y;
	else
		ydif = rooms[1]->y - rooms[0]->y;
	return (pythag(xdif, ydif));
}

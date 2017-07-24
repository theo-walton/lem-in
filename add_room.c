/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:54:44 by twalton           #+#    #+#             */
/*   Updated: 2017/07/19 22:54:44 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static char	*get_name(char *str)
{
	int i;
	char *ret;

	i = 0;
	while (str[i] != ' ')
		++i;
	str[i] = '\0';
	if (!(ret = ft_strdup(str)))
	{
		str[i] = ' ';
		return (NULL);
	}
	str[i] = ' ';
	return (ret);
}

static int	get_x_coor(char *str)
{
	int i;

	i = -1;
	while (str[++i] != ' ')
		;
	return (ft_atoi(str + i));
}

static int	get_y_coor(char *str)
{
	int i;

	i = -1;
	while (str[++i] != ' ')
		;
	while (str[++i] != ' ')
		;
	return (ft_atoi(str + i));
}

static	int	room_type_2(t_info *info, char *str)
{
	if (info->end.name)
		return (0);
	if (!(info->end.name = get_name(str)))
		return (0);
	info->end.x = get_x_coor(str);
	info->end.y = get_y_coor(str);
	return (1);
}

int	add_room(t_info *info, int room_type, char *str)
{
	int i;

	i = 0;
	if (room_type == 1)
	{
		if (info->start.name)
			return (0);
		if (!(info->start.name = get_name(str)))
			return (0);
		info->start.x = get_x_coor(str);
		info->start.y = get_y_coor(str);
		return (1);
	}
	if (room_type == 2)
		return (room_type_2(info, str));
	while ((info->rooms)[i].name)
		i++;
	if (!((info->rooms)[i].name = get_name(str)))
		return (0);
	(info->rooms)[i].x = get_x_coor(str);
	(info->rooms)[i].y = get_y_coor(str);
	return (1);
}

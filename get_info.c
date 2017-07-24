/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:03:08 by twalton           #+#    #+#             */
/*   Updated: 2017/07/18 16:03:08 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int	check_str_defined(char *str, t_info *info)
{
	int i;
	int toggle;

	i = 0;
	toggle = 0;
	while ((info->rooms)[i].name)
	{
		if (!ft_strcmp(str, (info->rooms)[i].name))
			toggle = 1;
		++i;
	}
	if (!ft_strcmp(str, info->start.name))
		toggle = 1;
	if (!ft_strcmp(str, info->end.name))
		toggle = 1;
	if (toggle == 1)
		return (1);
	return (0);
}

static int	check_link_names_defined(t_info *info)
{
	int i;

	i = 0;
	while ((info->links)[i].r1)
	{
		if (!check_str_defined((info->links)[i].r1, info))
			return (0);
		if (!check_str_defined((info->links)[i].r2, info))
			return (0);
		++i;
	}
	return (1);
}

static int	free_rooms_and_links(t_info *info)
{
	free_rooms(info);
	free_links(info);
	return (0);
}

int	get_info(t_info *info)
{
	char *str;
	int i;

	i = 0;
	if (!(str = ft_dirty_read(0, 1000000)))
		return (0);
	if (!(info->ant_num = get_ant_numbers(str, &i)))
		return (0);
	if (!get_rooms(str, info, &i))
		return (0);
	if (!get_links(str, info, &i))
	{
		free_rooms(info);
		return (0);
	}
	if (!(check_sufficient_info(info)))
		return (free_rooms_and_links(info));
	if (!(check_link_names_defined(info)))
		return (free_rooms_and_links(info));
	if (str[i] != '\0')
		return (free_rooms_and_links(info));
	if (!(check_duplicates(info)))
		return (free_rooms_and_links(info));
	return (1);
}

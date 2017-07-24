/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 02:45:48 by twalton           #+#    #+#             */
/*   Updated: 2017/07/20 02:45:48 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	initialize_info(t_info *info)
{
	info->ant_num = -1;
	info->start.name = NULL;
	info->end.name = NULL;
	if (!(info->rooms = ft_memalloc(sizeof(t_room) * 10000)))
		return (0);
	if (!(info->links = ft_memalloc(sizeof(t_link) * (10000))))
	{
		free(info->rooms);
		return (0);
	}
	return (1);
}

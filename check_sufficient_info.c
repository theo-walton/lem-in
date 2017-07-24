/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sufficient_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:50:21 by twalton           #+#    #+#             */
/*   Updated: 2017/07/21 17:50:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	check_sufficient_info(t_info *info)
{
	if (info->ant_num <= 0)
		return (0);
	if (!info->start.name)
		return (0);
	if (!info->end.name)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 02:25:21 by twalton           #+#    #+#             */
/*   Updated: 2017/07/20 02:25:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	free_links(t_info *info)
{
	int i;

	i = 0;
	while ((info->links)[i].r1)
	{
		free((info->links)[i].r1);
		free((info->links)[i].r2);
		++i;
	}
	free(info->links);
}

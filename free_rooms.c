/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 00:59:16 by twalton           #+#    #+#             */
/*   Updated: 2017/07/20 00:59:16 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_rooms(t_info *info)
{
	int i;

	i = 0;
	free(info->start.name);
	free(info->end.name);
	while ((info->rooms)[i])
	{
		free((info->rooms)[i].name);
		free((info->rooms)[i++]);
	}
}

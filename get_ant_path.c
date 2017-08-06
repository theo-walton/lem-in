/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ant_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 07:03:09 by twalton           #+#    #+#             */
/*   Updated: 2017/07/25 07:03:09 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static char	**get_path_arr(t_dataroom *finish)
{
	t_dataroom *current;
	char **strarr;
	int i;

	current = finish;
	i = 0;
	if (!(strarr = ft_memalloc(sizeof(char*) * 10000)))
		return (NULL);
	while (current->type != 2)
	{
		strarr[i] = current->name;
		current = go_to_previous_room(current);
		++i;
	}
	strarr[i] = current->name;
	return (strarr);
}

static int	fill_dfs(t_dataroom *room_arr, int i, int j, double min)
{
	t_dataroom *a;

	a = NULL;
	while (room_arr[i].name)
	{
		while (room_arr[i].links[j])
		{
			if (room_arr[i].dfs != -1 && room_arr[i].links[j]->dfs == -1)
			{
				if (room_arr[i].dists[j] + room_arr[i].dfs < min)
				{
					min = room_arr[i].dists[j] + room_arr[i].dfs;
					a = room_arr[i].links[j];
				}
			}
			++j;
		}
		j = 0;
		++i;
	}
	if (!a)
		return (0);
	a->dfs = min;
	return (1);
}

char	**get_ant_path(t_dataroom *room_arr)
{
	int i;
	char **ret;

	i = -1;
	while (fill_dfs(room_arr, 0, 0, 9999999999))
		;
	if (room_arr[1].dfs == -1)
		return (NULL);
	ret = get_path_arr(room_arr + 1);
	return (ret);
}

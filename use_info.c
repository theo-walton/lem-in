/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:06:10 by twalton           #+#    #+#             */
/*   Updated: 2017/07/24 23:06:10 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	use_info(t_info *info)
{
	t_dataroom *start;
	int i;
	char **ant_path;

	i = 0;
	if (!(start = convert_info_to_map(info)))
		return (0);
	if (!(ant_path = get_ant_path(start)))
	{
		free(start);
		return (0);
	}
	while (start[i].type != 3)
		++i;
	print_result(info, ant_path, start[i].dfs);
	return (1);
}

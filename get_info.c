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

int	get_info(t_info *info)
{
	char *str;
	int i;

	i = 0;
	if (!(str = read_from_stdout()))
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
	return (1);
}

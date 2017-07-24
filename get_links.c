/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 01:09:34 by twalton           #+#    #+#             */
/*   Updated: 2017/07/20 01:09:34 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int	dash_count(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == '-')
			ret++;
		++i;
	}
	return (ret);
}

static int	is_valid_name(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '-' && str[i] != '\n' && str[i] != ' ')
	{
		if (!ft_isprint(str[i]))
			return (0);
		++i;
	}
	return (1);
}

static int	is_line_valid(char *str)
{
	int i;

	i = 0;
	if (is_line_comment(str))
		return (1);
	if (is_line_command(str))
		return (1);
	if (str[0] == '\0')
		return (0);
	if (str[1] == 'L')
		return (0);
	if (dash_count(str) != 1)
		return (0);
	while (str[i++] != '-')
		;
	if (!is_valid_name(str))
		return (0);
	if (!is_valid_name(str + i + 1))
		return (0);
	return (1);
}

int	get_links(char *str, t_info *info, int *i)
{
	while (is_line_valid(str + *i))
	{
		if (is_line_comment(str + *i))
			;
		else if (is_line_command(str + *i))
			;
		else
		{
			if (!add_link(info, str + *i))
			{
				free_links(info);
				return (0);
			}
		}
		go_to_next_line(str, i);
	}
	return (1);
}

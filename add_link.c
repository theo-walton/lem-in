/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 01:59:13 by twalton           #+#    #+#             */
/*   Updated: 2017/07/20 01:59:13 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	add_link2(t_link links, char *str, int i)
{
	int k;

	k = i;
	while (str[i] != '\0' && str[i] != '\n')
		++i;
	if (str[i] == '\0')
	{
		if (!(links.r2 = ft_strdup(str + k)))
		{
			free(links.r1);
			return (0);
		}
	}
	else
	{
		str[i] = '\0';
		if (!(links.r2 = ft_strdup(str + k)))
		{
			free(links.r1);
			return (0);
		}
		str[i] = '\n';
	}
	return (1);
}

int	add_link(t_info *info, char *str)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] != '-')
		++i;
	str[i] = '\0';
	while ((info->links)[x])
		++x;
	if (!((info->links)[x].r1 = ft_strdup(str)))
		return (0);
	str[i++] = '-';
	return (add_link2((info->links)[x], str, i));
}

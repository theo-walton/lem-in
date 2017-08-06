/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 23:22:05 by twalton           #+#    #+#             */
/*   Updated: 2017/08/05 23:22:05 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void	putintdouble(double x)
{
	char str[100];
	int i;

	i = 99;
	while (x >= 10)
	{
		str[i--] = ((unsigned long long)x % 10) + '0';
		x = x / 10;
	}
	str[i] = ((unsigned long long)x + '0');
	write(1, str + i, 100 - i);
}

static void	print_info2(t_info *info)
{
	int i;

	i = 0;
	while (info->rooms[i].name)
	{
		ft_putstr(info->rooms[i].name);
		ft_putstr(" - (");
		ft_putnbr(info->rooms[i].x);
		ft_putstr(", ");
		ft_putnbr(info->rooms[i++].y);
		ft_putchar(')');
		ft_putstr("\n                  ");
	}
	ft_putstr("\n       Ant Links:\n\n");
	i = 0;
	while (info->links[i].r1)
	{
		ft_putstr(info->links[i].r1);
		ft_putstr(" <--> ");
		ft_putstr(info->links[i++].r2);
		ft_putchar('\n');
	}
}

static void	print_info(t_info *info)
{
	ft_putstr("\n  Number of Ants: ");
	ft_putnbr(info->ant_num);
	ft_putchar('\n');
	ft_putstr("\n      Start room: ");
	ft_putstr(info->start.name);
	ft_putstr(" - (");
	ft_putnbr(info->start.x);
	ft_putstr(", ");
	ft_putnbr(info->start.y);
	ft_putchar(')');
	ft_putstr("\n        End room: ");
	ft_putstr(info->end.name);
	ft_putstr(" - (");
	ft_putnbr(info->end.x);
	ft_putstr(", ");
	ft_putnbr(info->end.y);
	ft_putchar(')');
	ft_putstr("\n     Other rooms: ");
	print_info2(info);
}

void	print_result(t_info *info, char **ant_path, double dfs)
{
	if (info->mode == 1)
	{
		ft_putstr(info->file);
		if (info->file[ft_strlen(info->file) - 1] != '\n')
			ft_putchar('\n');
		print_ants(info, ant_path);
		return ;
	}
	else
		print_info(info);
	ft_putstr("\n       Ant Moves:\n");
	print_ants(info, ant_path);
	ft_putstr("\n  Path Distance: ");
	putintdouble(dfs);
	ft_putstr("\n\n");
}

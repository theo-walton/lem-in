/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 22:08:23 by twalton           #+#    #+#             */
/*   Updated: 2017/08/02 22:08:23 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void	print_part_1(int i, char **ant_path, int room_tot)
{
	while (i)
	{
		ft_putchar('L');
		ft_putnbr(i--);
		ft_putchar('-');
		ft_putstr(ant_path[--room_tot]);
		if (i)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

static void	print_part_2(int i, char **ant_path, int room_tot)
{
	while (room_tot)
	{
		ft_putchar('L');
		ft_putnbr(i--);
		ft_putchar('-');
		ft_putstr(ant_path[--room_tot]);
		if (room_tot)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

static void	print_part_3(int i, char **ant_path, int room_tot, int ant_num)
{
	int n;

	n = room_tot + ant_num - i;
	while (ant_num)
	{
		ft_putchar('L');
		ft_putnbr(ant_num--);
		ft_putchar('-');
		ft_putstr(ant_path[--n]);
		if (ant_num)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

static void	print_part_4(int i, char **ant_path, int room_tot, int ant_num)
{
	int n;

	n = room_tot + ant_num - i;
	while (n)
	{
		ft_putchar('L');
		ft_putnbr(ant_num--);
		ft_putchar('-');
		ft_putstr(ant_path[--n]);
		if (n)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	print_ants(t_info *info, char **ant_path)
{
	int room_tot;
	int ant_num;
	int i;

	i = 0;
	ant_num = info->ant_num;
	room_tot = 0;
	while (ant_path[room_tot])
		++room_tot;
	ant_path[room_tot--] = NULL;
	while (i <= ant_num && i <= room_tot)
		print_part_1(i++, ant_path, room_tot);
	while (i > room_tot && i <= ant_num)
		print_part_2(i++, ant_path, room_tot);
	while (i > ant_num && i <= room_tot)
		print_part_3(i++, ant_path, room_tot, ant_num);
	while (i < ant_num + room_tot)
		print_part_4(i++, ant_path, room_tot, ant_num);
}

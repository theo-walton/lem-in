/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:52:48 by twalton           #+#    #+#             */
/*   Updated: 2017/07/18 14:52:48 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	main(int ac, char **av)
{
	t_info info;

	if (!initialize_info(&info))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ac >= 2 && !ft_strcmp(av[1], "-raw"))
		info.mode = 1;
	else
		info.mode = 0;
	if (!get_info(&info))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!use_info(&info))
	{
		write(2, "Error\n", 6);
		return (1);
	}
}

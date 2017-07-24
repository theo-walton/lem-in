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

int	main(void)
{
	t_info info;

	if (!initialize_info(&info))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!get_info(&info))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	write(1, "Valid\n", 6);
}

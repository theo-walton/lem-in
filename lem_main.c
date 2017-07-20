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

int	main(void)
{
	t_info info;

	initialize_info(info);
	if (!get_info(&info))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!check_sufficient_info(info))
	{
		write(2, "Error\n", 6);
		free_rooms(info);
		free_links(info);
		return (1);
	}
}

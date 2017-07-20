/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:33:52 by twalton           #+#    #+#             */
/*   Updated: 2017/07/19 20:33:52 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_end(char *str)
{
	if (str[2] == 'e' && str[3] == 'n' && str[4] == 'd')
		return (1);
	return (0);
}

static int	is_start(char *str)
{
	if (str[2] == 's' && str[3] == 't' && str[4] == 'a')
	{
		if (str[5] == 'r' && str[6] == 't')
			return (1);
		return (0);
	}
	return (0);
}

int	is_line_command(char *str)
{
	int i;

	i = 2;
	if (str[0]  != '#' || str[1] != '#')
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == '#')
			return (-1);
		++i;
	}
	if (i == 4)
	{
		if (is_end(str))
			return (2);
	}
	if (i == 6)
	{
		if (is_start(str))
			return (1);
	}
	return (3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:37:41 by twalton           #+#    #+#             */
/*   Updated: 2017/07/19 18:37:41 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	space_count(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == ' ')
			ret++;
		++i;
	}
	return (ret);
}

static int	is_valid_num(char *str)
{
	int sign;
	int n;

	sign = 0;
	if (str[0] == '-')
		sign = 1;
	n = ft_atoi(str);
	if ((sign == 1 && n == 0) || (sign == 0 && n == -1))
		return (0);
	n = 0;
	if (sign)
		++n;
	while (n != '\0' && n != '\n' && n != ' ')
	{
		if (!ft_isdigit(str[n]))
			return (0);
	}
	return (1);
}

static int	is_line_valid(char *str)
{
	int i;

	i = 0;
	if (is_line_comment(str))
		return (1);
	if (is_line_command(str) != -1)
		return (1);
	if (str[1] == 'L')
		return (0);
	if (space_count(str) != 2)
		return (0);
	while (str[i] != ' ')
		++i;
	if (!is_valid_num(str + i++))
		return (0);
	while (str[i] != ' ')
		++i;
	if (!is_valid_num(str + i))
		return (0);
	return (1);
}

int	get_rooms(char *str, t_info *info, int *i)
{
	int room_type;

	room_type = 0;
	while (is_line_valid(str + *i))
	{
		if (is_line_comment(str + *i))
			;
		else if ((room_type = is_line_command(str + *i)))
			;
		else
		{
			if (!add_room(info, room_type, str + *i))
			{
				free_rooms(info);
				return (0);
			}
			room_type = 0;
		}
		go_to_next_line(str, i);
	}
	return (1);
}

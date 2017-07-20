/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ant_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:23:40 by twalton           #+#    #+#             */
/*   Updated: 2017/07/18 16:23:40 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_ant_numbers(char *str, int *i)
{
	int k;

	while (is_line_comment(str + *i))
		go_to_next_line(str, i);
	k = i;
	if (str[k] == '0')
		return (NULL);
	while (str[k] != '\n' && str[k] != '\0')
	{
		if (!ft_isdigit(str[k]) || k - *i > 11)
			return (NULL);
		k++;
	}
	k = ft_atoi(str + *i);
	go_to_next_line(str, i);
	if (k == -1)
		return (NULL);
	return (k);
}

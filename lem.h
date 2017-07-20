/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:54:58 by twalton           #+#    #+#             */
/*   Updated: 2017/07/18 16:54:58 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

struct s_room
{
	char *name;
	int x;
	int y;
}	t_room;

struct s_link
{
	char *r1;
	char *r2;
}	t_link;

struct s_str
{
	int ant_num;
	t_room start;
	t_room end;
	t_room *rooms;
	t_link *links;
}	t_info;

#endif

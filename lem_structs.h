/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:54:58 by twalton           #+#    #+#             */
/*   Updated: 2017/07/18 16:54:58 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_STRUCTS_H
# define LEM_STRUCTS_H

typedef struct s_room
{
	char *name;
	int x;
	int y;
}	t_room;

typedef struct s_link
{
	char *r1;
	char *r2;
}	t_link;

typedef struct s_str
{
	int ant_num;
	int mode;
	char *file;
	t_room start;
	t_room end;
	t_room *rooms;
	t_link *links;
}	t_info;

typedef struct s_roomdata
{
	int type;
	char *name;
	double dfs;
	struct s_roomdata **links;
	double *dists;
}	t_dataroom;

#endif

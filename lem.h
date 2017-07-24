/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 00:02:40 by twalton           #+#    #+#             */
/*   Updated: 2017/07/24 00:02:40 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include "lem_structs.h"

int	add_link(t_info *info, char *str);
int	add_room(t_info *info, int room_type, char *str);
int	check_duplicates(t_info *info);
int	check_sufficient_info(t_info *info);
void	free_links(t_info *info);
void	free_rooms(t_info *info);
int	get_ant_numbers(char *str, int *i);
int	get_info(t_info *info);
int	get_links(char *str, t_info *info, int *i);
int	get_rooms(char *str, t_info *info, int *i);
void	go_to_next_line(char *str, int *i);
int	initialize_info(t_info *info);
int	is_line_command(char *str);
int	is_line_comment(char *str);

#endif

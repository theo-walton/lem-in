# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twalton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 00:15:27 by twalton           #+#    #+#              #
#    Updated: 2017/07/24 00:15:29 by twalton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = add_link.c \
add_room.c \
check_duplicates.c \
check_sufficient_info.c \
free_links.c \
free_rooms.c \
get_ant_numbers.c \
get_info.c \
get_links.c \
get_rooms.c \
go_to_next_line.c \
initialize_info.c \
is_line_command.c \
is_line_comment.c \
lem_main.c \
\
$(addprefix libft/, \
\
ft_atoi.c \
ft_dirty_read.c \
ft_isdigit.c \
ft_isprint.c \
ft_memalloc.c \
ft_strcmp.c \
ft_strdup.c \
ft_bzero.c \
ft_strlen.c \
ft_memset.c \
\
)

OBJ = *.o

HEADERS = -I . -I ./libft/includes/.

FLAGS = -Wfatal-errors -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) $(HEADERS)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
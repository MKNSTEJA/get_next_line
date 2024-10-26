# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 23:39:36 by mknsteja          #+#    #+#              #
#    Updated: 2024/10/18 11:06:38 by mknsteja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
CFLAGS = -Wall -Werror -Wextra
SRCS = get_next_line.c get_next_line_utils.c 
OBJS = $(SRCS:.c=.o) 

all: $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
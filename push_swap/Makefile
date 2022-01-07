# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 18:40:09 by wchae             #+#    #+#              #
#    Updated: 2022/01/07 18:46:23 by wchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rc

NAME = push_swap

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft.a

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.o<=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)


clean :
	rm -rf $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 02:26:53 by wchae             #+#    #+#              #
#    Updated: 2021/12/17 02:43:18 by wchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rc

NAME = 	libftprintf.a

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft.a
#INCS = .

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) #-I$(INCS)

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

test : re
	make all -C $(LIBFT)/
	$(CC) -o test -g3 $(SRCS) detail_testcase.c -L./libft -l ft
run_test : test
	./test
re : fclean all

.PHONY : all clean fclean

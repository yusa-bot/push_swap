# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 21:08:58 by ayusa             #+#    #+#              #
#    Updated: 2025/07/05 18:56:44 by ayusa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard ./*.c)
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

LIBFT_DIR = libft
ft_printf_DIR = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
ft_printf = $(ft_printf_DIR)/ft_printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(ft_printf) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(ft_printf) $(LIBFT)

$(ft_printf): $(LIBFT)
	make -C $(ft_printf_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(ft_printf_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(ft_printf_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

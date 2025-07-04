# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 00:02:40 by ayusa             #+#    #+#              #
#    Updated: 2025/05/06 17:37:31 by ayusa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

SRCS        = $(filter-out %bonus.c, (wildcard ft_*.c))
BONUS_SRCS  = $(wildcard ft_*bonus.c)

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)


bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
# 既に作った libft.a に bonus を 追加 する形


#.o
clean:
	#$(RM) $(OBJS) $(BONUS_OBJ)

#.o → .a
fclean: clean
	$(RM) $(NAME)

#全部削除してからもう一度ビルド
re: fclean all

.PHONY: all clean fclean re bonus

make        # mandatoryだけビルド
make bonus  # mandatory + bonusビルド
make clean  # 中間ファイル削除
make fclean # libft.aも削除
make re     # 再構築

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 10:14:06 by pnamnil           #+#    #+#              #
#    Updated: 2024/01/03 17:18:41 by npiyapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

LIBFT_PATH = libft
INCLUDE = $(LIBFT_PATH)/include
LIBFT = -L$(LIBFT_PATH) -lft

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE)

SRCS = $(addprefix src/, push_swap.c parse_arg.c lst_int.c push_swap_utils.c operate.c \
						instruction.c sort_three.c lst_int_2.c cal_cost.c operate_2.c \
						push_to_A.c operate3.c operate4.c operate5.c do_rotate.c \
						do_reverse_rotate.c)
OBJS = $(patsubst src/%.c, bin/%.o, $(SRCS))

SRCS_BONUS = $(addprefix src/, checker.c parse_arg.c lst_int.c push_swap_utils.c operate.c \
						instruction.c sort_three.c lst_int_2.c cal_cost.c operate_2.c \
						push_to_A.c operate3.c operate4.c operate5.c do_rotate.c \
						do_reverse_rotate.c checker_1.c checker_2.c checker_rotate.c)
OBJS_BONUS = $(patsubst src/%.c, bin/%.o, $(SRCS_BONUS))

INCLUDES = $(INCLUDE)/*.h

bin/%.o: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME) $(NAME_BONUS)

bonus:	$(NAME) $(NAME_BONUS)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(LIBFT) -lft $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(LIBFT) -lft $(OBJS_BONUS) -o $(NAME_BONUS)

${OBJS}: ${INCLUDES}

clean:
	rm -rf bin
	rm $(NAME)
	rm $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re

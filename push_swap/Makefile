# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jburlama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 19:32:54 by jburlama          #+#    #+#              #
#    Updated: 2024/01/21 18:27:15 by jburlama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CFILES = main.c stack.c operations.c operations2.c free.c \
		 push_swap.c  push_swap2.c push_swap_utils.c push_swap_utils2.c \
		 loop.c cost.c
BONUS_CFILES = checker.c $(GET_NEXT_LINE) operations.c operations2.c stack.c \
			   free.c push_swap_utils.c ft_strcmp.c
LIBFT = libft/libft.a
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

all: $(NAME) bonus

$(NAME): $(CFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME) $(LIBFT)

bonus: $(BONUS_CFILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(BONUS)

$(LIBFT):
	@make -C libft

clean:
	$(RM) $(NAME)
	@make clean -C ./libft
	$(RM) $(BONUS)

fclean: clean
	$(RM) $(LIBFT)

re: fclean $(NAME)

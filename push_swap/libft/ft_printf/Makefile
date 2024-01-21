# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jburlama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 12:35:04 by jburlama          #+#    #+#              #
#    Updated: 2024/01/06 19:32:01 by jburlama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
RM = rm -f
NAME = libftprintf.a
LIBDIR = ./Libft
LIBAR = ./Libft/libft.a
CFILES = ft_printf.c print_char.c print_string.c print_ptr.c print_decimal.c print_unsigned_dec.c\
		print_decimal2.c print_hexa.c
OBJS = ${CFILES:.c=.o}

all: $(NAME)

$(NAME): $(LIBAR) $(OBJS)
	cp $< $(NAME)
	$(AR) $@ $^

OBJS: $(CFILES)
	$(CC) $(CFLAGS) -c $^

$(LIBAR): $(LIBDIR)
	@make all -C $^

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBDIR)

fclean: clean
	$(RM) libftprintf.a
	$(RM) $(LIBAR)

re: fclean $(NAME)

.PHONY: clean fclean re all

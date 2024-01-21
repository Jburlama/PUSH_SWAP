# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jburlama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 19:20:36 by jburlama          #+#    #+#              #
#    Updated: 2024/01/21 17:11:20 by jburlama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		 ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		 ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		 ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		 ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
		 ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
OBJS = ${CFILES:.c=.o}
FT_PRINTF_DIR = ft_printf
FT_PRINTF_AR = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_AR)
	cp $(FT_PRINTF_AR) $(NAME)
	$(AR) $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $^

$(FT_PRINTF_AR): $(FT_PRINTF_DIR)
	@make all -C $<

clean:
	@make clean -C $(FT_PRINTF_DIR)
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(FT_PRINTF_AR)

re: fclean all

.PHONY: all clean fclean re

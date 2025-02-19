# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 15:03:31 by jnauroy           #+#    #+#              #
#    Updated: 2024/11/04 18:18:52 by jnauroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MY_SOURCES = ft_printf.c \
			 ft_hexa.c \
			 ft_putchar.c \
			 ft_putnbr.c \
			 ft_putptr.c \
			 ft_putstr.c \
			 ft_usint.c

AR = ar -rcs
CC = cc
CFLAGS += -Wall -Wextra -Werror

OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

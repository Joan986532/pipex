# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 17:52:30 by jnauroy           #+#    #+#              #
#    Updated: 2025/02/24 14:44:25 by jnauroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_DIR = sources
OBJ_DIR = objects
HEAD_DIR = headers

NAME = pipex

SOURCES = $(SRC_DIR)/pipex.c \
			 $(SRC_DIR)/parsing_files.c \
			 $(SRC_DIR)/pipex_utils.c \
			 $(SRC_DIR)/cleanup.c \
			 $(SRC_DIR)/pipex_program.c \
			 $(SRC_DIR)/get_path.c \

OBJECTS = $(SOURCES:%.c=%.o)

LIBFT = Libft_pipex/libft.a
PRINTF = ft_printf/libftprintf.a

CFLAGS = -g -Wall -Wextra -Werror

#--------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ft_printf
	$(MAKE) -C Libft_pipex
	cc $(OBJECTS) $(LIBFT) $(PRINTF) $(CFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C ft_printf
	$(MAKE) clean -C Libft_pipex
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re all

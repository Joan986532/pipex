# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 17:52:30 by jnauroy           #+#    #+#              #
#    Updated: 2025/02/19 15:26:35 by jnauroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = pipex.c \
			 parsing_files.c \
			 error_functions.c \
			 cleanup.c \
			 pipex_program.c \
			 get_path.c \
			 outfile_process.c

OBJECTS = $(SOURCES:.c=.o)

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

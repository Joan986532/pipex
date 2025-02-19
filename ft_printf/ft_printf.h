/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:26:51 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/18 16:54:47 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(int fd, const char *format, ...);
void	ft_hexa(int fd, unsigned int value, size_t *writ_char, const char form);
void	ft_putchar(int fd, char c, size_t *written_char);
void	ft_putnbr(int fd, int n, size_t *written_char);
void	ft_putptr(int fd, void *ptr, size_t *written_char);
void	ft_putstr(int fd, char *string, size_t *written_char);
void	ft_usint(int fd, unsigned int n, size_t *written_char);

#endif

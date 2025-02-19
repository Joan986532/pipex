/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:58:36 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/18 16:11:06 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	arg_format(int fd, const char format, va_list param, size_t *writt_char)
{
	if (format == 'c')
		ft_putchar(fd, va_arg(param, int), writt_char);
	else if (format == 'd' || format == 'i')
		ft_putnbr(fd, va_arg(param, int), writt_char);
	else if (format == 'u')
		ft_usint(fd, va_arg(param, unsigned int), writt_char);
	else if (format == 's')
		ft_putstr(fd, va_arg(param, char *), writt_char);
	else if (format == 'p')
		ft_putptr(fd, va_arg(param, void *), writt_char);
	else if (format == 'x' || format == 'X')
		ft_hexa(fd, va_arg(param, unsigned int), writt_char, format);
	else if (format == '%')
	{
		write(fd, "%", 1);
		(*writt_char)++;
	}
	else
	{
		write(fd, "%", 1);
		write(fd, &format, 1);
		(*writt_char) += 2;
	}
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	parameter;
	size_t	written_char;

	written_char = 0;
	va_start(parameter, format);
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			arg_format(fd, *(format + 1), parameter, &written_char);
			format++;
		}
		else
			ft_putchar(fd, *format, &written_char);
		format++;
	}
	va_end(parameter);
	return (written_char);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:20:42 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/18 17:03:25 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_writeptr(int fd, size_t address, size_t *written_char)
{
	const char	*base;
	size_t		num;

	base = "0123456789abcdef";
	if (address > 15)
	{
		ft_writeptr(fd, address / 16, written_char);
		ft_writeptr(fd, address % 16, written_char);
	}
	else
	{
		num = base[address];
		write(fd, &num, 1);
		(*written_char)++;
	}
}

void	ft_putptr(int fd, void *ptr, size_t *written_char)
{
	size_t	address;

	if (!ptr)
	{
		write(fd, "(nil)", 5);
		(*written_char) += 5;
		return ;
	}
	write(fd, "0x", 2);
	*(written_char) += 2;
	address = (size_t) ptr;
	ft_writeptr(fd, address, written_char);
}

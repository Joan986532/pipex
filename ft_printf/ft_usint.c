/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:40:52 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/18 17:03:48 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_usint(int fd, unsigned int n, size_t *written_char)
{
	unsigned int	nb;

	if (n < 0)
		return ;
	if (n > 9)
	{
		ft_putnbr(fd, n / 10, written_char);
		ft_putnbr(fd, n % 10, written_char);
	}
	else
	{
		nb = n + 48;
		write(fd, &nb, 1);
		(*written_char)++;
	}
}

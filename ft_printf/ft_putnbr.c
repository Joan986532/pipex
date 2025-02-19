/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:32:34 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/18 17:00:38 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int fd, int n, size_t *written_char)
{
	int	nb;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		*written_char += 11;
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		(*written_char)++;
	}
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

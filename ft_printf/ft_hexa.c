/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:50:46 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/18 16:55:57 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(int fd, unsigned int value, size_t *writ_char, const char form)
{
	const char		*base;
	unsigned int	num;

	base = "0123456789abcdef";
	if (value > 15)
	{
		ft_hexa(fd, value / 16, writ_char, form);
		ft_hexa(fd, value % 16, writ_char, form);
	}
	else
	{
		num = base[value];
		if (form == 'X')
		{
			if (num >= 'a' && num <= 'f')
				num -= 32;
		}
		write(1, &num, 1);
		(*writ_char)++;
	}
}

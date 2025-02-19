/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:45:56 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/18 16:12:15 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(int fd, char *string, size_t *written_char)
{
	if (!string)
	{
		write(fd, "(null)", 6);
		(*written_char) += 6;
		return ;
	}
	while (*string)
	{
		write(fd, string++, 1);
		(*written_char)++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:25:38 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/19 09:34:15 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_error(t_error a, char *f, int l)
{
	if (a == ER_MALLOC)
		ft_printf(2, "Error: malloc\n%s / %d.\n", f, l);
	else if (a == ER_CMD)
		ft_printf(2, "Error: cmd\n%s / %d.\n", f, l);
	else if (a == ER_PIPE)
		ft_printf(2, "Error: pipe\n%s / %d.\n", f, l);
	else if (a == ER_ENVP)
		ft_printf(2, "Error: PATH doesn't exist\n%s / %d.\n", f, l);
	else if (a == ER_JOIN)
		ft_printf(2, "Error: join fail\n%s / %d.\n", f, l);
	return (1);
}

int	ft_access_error(const char *file, char *f, int l)
{
	if (access(file, F_OK))
		ft_printf(2, "Error: no %s\n%s / %d.\n", file, f, l);
	else if (access(file, W_OK | R_OK | X_OK))
		ft_printf(2, "Error: %s no perm\n%s / %d.\n", file, f, l);
	return (1);
}

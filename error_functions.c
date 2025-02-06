/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:25:38 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/06 16:02:17 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_error(int error, char *spot)
{
	if (error == ER_MALLOC)
		printf("Error: %s Malloc failed.\n", spot);
	else if (error == ER_CMD)
		printf("Error: %s doesn't exist.\n", spot);
	return (1);
}

int	ft_access_error(const char *file)
{
	if (access(file, F_OK))
		printf("Error: (access) File doesn't exist.\n");
	else if (access(file, W_OK | R_OK | X_OK))
		printf("Error: (access) Permission denied.\n");
	return (1);
}

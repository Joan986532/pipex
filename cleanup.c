/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:03:41 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/06 16:30:43 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_freesplit_pipex(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	return (0);
}

int	ft_cleanup(t_utils *infos, int code)
{
	if (code == 1)
	{
		free(infos->cmd1_join);
		ft_freesplit_pipex(infos->cmd1_split);
		return (ft_error(ER_CMD, "(cmd1)"));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:33:28 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/06 14:40:16 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**ft_create_cmd(char *argv)
{
	const char	**cmd_line;

	cmd_line = ft_split(argv, " ");
	if (!cmd_line)
		return (NULL);
	return (cmd_line);
}

int	main(int argc, char **argv, char **envp)
{
	t_utils	infos;

	if (argc != 5)
		return (1);
	if (ft_pars_global(argc, argv, envp, &infos))
		return (1);
}

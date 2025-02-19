/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:33:28 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/19 11:20:53 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_utils	infos;
	t_list	*cmds;
	int		i;

	i = 0;
	cmds = NULL;
	if (argc < 5)
		return (1);
	if (ft_pars_global(argc, argv, envp, &infos))
		return (1);
	if (ft_pars_init_cmd(&infos, argv, argc, &cmds))
		return (1);
	if (ft_fill_pathnames_all(&infos, &cmds))
		return (1);
	while (i < infos.cmd_count)
	{
		if (ft_pipex_prg(&infos, &cmds, envp, &i))
			return (1);
		i++;
	}
	return (0);
}

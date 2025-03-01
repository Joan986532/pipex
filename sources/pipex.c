/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:33:28 by jnauroy           #+#    #+#             */
/*   Updated: 2025/03/01 14:37:06 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <headers/pipex.h>

int	main(int argc, char **argv, char **envp)
{
	t_utils	infos;
	t_list	*cmds;

	cmds = NULL;
	if (argc < 5)
		return (1);
	if (ft_pars_global(argc, argv, envp, &infos))
		return (1);
	if (ft_pars_init_cmd(&infos, argv, argc, &cmds))
		return (1);
	infos.tmp = dup(STDIN_FILENO);
	while (infos.i < infos.cmd_count)
	{
		ft_pipex_prg(argv, &infos, &cmds, envp);
		infos.i++;
	}
	ft_clean_tab(infos.paths);
	ft_lstclear_pipex(&cmds);
	ft_wait_pid(&infos);
	return (0);
}

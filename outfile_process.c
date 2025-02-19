/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfile_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:03:31 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/19 18:11:10 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_exe_outfile(t_utils *infos, t_list **cmds, char **envp, int *i)
{
	t_list	*tmp;
	int		pid;
	int		j;

	j = 0;
	tmp = NULL;
	ft_get_cmds(tmp, cmds, i);
	pid = fork();
	if (pid == 0)
	{
		if (ft_outfile_process(infos->fdout, *cmds, envp))
			return (1);
		exit (0);
	}
	return (0);
}

int	ft_outfile_process(int fd_out, t_list *cmds, char **envp)
{
	char	*pathname_temp;
	char	**content_temp;

	pathname_temp = cmds->pathname;
	content_temp = cmds->content;
	cmds->pathname = NULL;
	cmds->content = NULL;
	//ft_lstclear_pipex(cmds);
	if (dup2(fd_out, STDOUT_FILENO) != -1)
	{
		close(fd_out);
		execve(pathname_temp, content_temp, envp);
	}
	free(pathname_temp);
	ft_clean_tab(content_temp);
	exit(1);
}

void	ft_get_cmds(t_list *tmp, t_list **cmd, int *i)
{
	int	j;

	j = 0;
	tmp = *cmd;
	while (j < *i)
	{
		tmp = tmp->next;
		j++;
	}
}

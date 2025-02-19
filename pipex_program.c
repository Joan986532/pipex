/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:31:20 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/19 18:13:07 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_child_process(int *fd, t_list *cmds, char **envp)
{
	char	*pathname_temp;
	char	**content_temp;

	pathname_temp = cmds->pathname;
	content_temp = cmds->content;
	cmds->pathname = NULL;
	cmds->content = NULL;
	//ft_lstclear_pipex(cmds);
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) != -1)
	{
		close(fd[1]);
		execve(pathname_temp, content_temp, envp);
	}
	close(fd[1]);
	free(pathname_temp);
	ft_clean_tab(content_temp);
	exit(1);
}

int	ft_parent_process(int *fd)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		write(2, "dup2 fail parent\n", 17);
		return (1);
	}
	close(fd[0]);
	return (0);
}

int	ft_init_pipe(int *pid, int *fd)
{
	if (pipe(fd) == -1)
	{
		printf("fail pipe\n");
		return (1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		printf("fail fork\n");
		return (1);
	}
	return (0);
}

int	ft_exe_pipex(t_utils *infos, t_list **cmds, char **envp, int *i)
{
	t_list	*tmp;
	int		fd[2];
	int		pid;
	int		j;

	j = 0;
	tmp = NULL;
	ft_get_cmds(tmp, cmds, i);
	if (ft_init_pipe(&pid, fd))
		return (1);
	if (pid == 0)
	{
		close(infos->fdout);
		if (ft_child_process(fd, tmp, envp))
			return (1);
		exit (0);
	}
	else
	{
		if (ft_parent_process(fd))
			return (1);
	}
	return (0);
}

int	ft_pipex_prg(t_utils *infos, t_list **cmds, char **envp, int *i)
{
	if (*i == 0)
	{
		if (dup2(infos->fdin, STDIN_FILENO) != -1)
		{
			close(infos->fdin);
			if (!ft_exe_pipex(infos, cmds, envp, i))
				return (0);
		}
	}
	else if (*i < infos->cmd_count - 1)
	{
		if (!ft_exe_pipex(cmds, envp, i))
			return (0);
	}
	else if (*i == infos->cmd_count - 1)
	{
		if (!ft_exe_outfile(infos, cmds, envp, i))
		{
			close(infos->fdout);
			return (0);
		}
	}
	return (1);
}

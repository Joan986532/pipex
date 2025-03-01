/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:31:20 by jnauroy           #+#    #+#             */
/*   Updated: 2025/03/01 15:24:21 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <headers/pipex.h>

int	ft_init_pipe(t_utils *infos, int *fd)
{
	if (pipe(fd) == -1)
	{
		ft_error(__FILE__, __LINE__);
		return (1);
	}
	infos->pid = fork();
	if (infos->pid == -1)
	{
		ft_error(__FILE__, __LINE__);
		return (1);
	}
	return (0);
}

int	ft_exe_pipex(t_utils *infos, t_list **cmds, t_list *tmp, char **envp)
{
	int		fd[2];

	if (ft_init_pipe(infos, fd))
		return (1);
	if (infos->pid == 0)
	{
		ft_child_process(fd, infos, tmp, envp);
		ft_close(infos);
		ft_lstclear_pipex(cmds);
		infos->numerror++;
		exit (127);
	}
	if (infos->i == 0)
		close(infos->fdin);
	if (infos->i == infos->cmd_count - 1)
		if (infos->fdout != -1)
			close(infos->fdout);
	close(fd[1]);
	close(infos->tmp);
	infos->tmp = dup(fd[0]);
	close(fd[0]);
	return (0);
}

void	ft_init_child(t_utils *infos)
{
	if (infos->i == 0)
	{
		close(infos->in);
		infos->in = dup(infos->fdin);
	}
	if (infos->i == infos->cmd_count - 1)
	{
		close(infos->out);
		infos->out = dup(infos->fdout);
	}
}

void	ft_child_process(int *fd, t_utils *infos, t_list *cmds, char **envp)
{
	close(fd[0]);
	infos->in = dup(infos->tmp);
	infos->out = dup(fd[1]);
	close(fd[1]);
	ft_init_child(infos);
	if (dup2(infos->in, STDIN_FILENO) != -1)
	{
		if (dup2(infos->out, STDOUT_FILENO) != -1)
		{
			ft_close(infos);
			if (cmds->pathname && cmds->content)
				execve(cmds->pathname, cmds->content, envp);
		}
	}
}

int	ft_pipex_prg(char **argv, t_utils *infos, t_list **cmds, char **envp)
{
	t_list	*temp;

	temp = *cmds;
	ft_get_cmds(&temp, infos);
	if (infos->i == 0)
	{
		if (ft_open_infile(argv[1], infos))
			return (1);
	}
	else if (infos->i == infos->cmd_count - 1)
	{
		if (ft_open_outfile(argv[infos->cmd_count + 2], infos))
			return (1);
	}
	ft_fill_pathnames(infos, temp);
	ft_exe_pipex(infos, cmds, temp, envp);
	return (0);
}

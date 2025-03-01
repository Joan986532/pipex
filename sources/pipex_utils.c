/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:25:38 by jnauroy           #+#    #+#             */
/*   Updated: 2025/03/01 15:24:40 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <headers/pipex.h>

int	ft_error(char *f, int l)
{
	char	*str;

	str = strerror(errno);
	ft_printf(2, "%s, %s, %d.\n", str, f, l);
	return (1);
}

int	ft_access_error(const char *file, char *f, int l)
{
	char	*str;

	str = strerror(errno);
	if (access(file, F_OK))
		ft_printf(2, "%s, %s, %d.\n", str, f, l);
	else if (access(file, W_OK | R_OK | X_OK))
		ft_printf(2, "%s, %s, %d.\n", str, f, l);
	return (1);
}

void	ft_get_cmds(t_list **tmp, t_utils *infos)
{
	int		j;

	j = 0;
	while (j < infos->i)
	{
		*tmp = (*tmp)->next;
		j++;
	}
}

void	ft_wait_pid(t_utils *infos)
{
	while (infos->i > 0)
	{
		waitpid(-1, NULL, 0);
		infos->i--;
	}
}

void	ft_close(t_utils *infos)
{
	close(infos->in);
	close(infos->out);
	if (infos->i == 0)
		if (infos->fdin != -1)
			close(infos->fdin);
	if (infos->i == infos->cmd_count - 1)
		if (infos->fdout != -1)
			close(infos->fdout);
	close(infos->tmp);
}

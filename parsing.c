/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:32:25 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/06 16:36:25 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_open_infile(const char *file, t_utils *infos)
{
	infos->fd = open(file, O_RDONLY);
	if (infos->fd == -1)
		return (ft_access_error(file));
	return (0);
}

int	ft_pars_envp(char **envp, t_utils *infos)
{
	size_t		size;
	char		*path;

	size = ft_strlen(envp[36]) - 5;
	path = ft_strdup(envp[36] + 5);
	if (!path)
		return (ft_error(ER_MALLOC, "(path)"));
	infos->paths = ft_split(path, ':');
	free(path);
	if (!infos->paths)
		return (ft_error(ER_MALLOC, "(infos.paths)"));
	return (0);
}

int	ft_pars_cmd(char *cmd, t_utils *infos)
{
	int		i;

	i = 0;
	infos->cmd1_split = ft_split(cmd, ' ');
	if (!infos->cmd1_split)
		return (ft_error(ER_MALLOC, "(infos.cmd1_split)"));
	while (infos->paths[i])
	{
		infos->cmd1_join = ft_strjoin(infos->paths[i], infos->cmd1_split[0]);
		if (!infos->cmd1_join)
			return (ft_error(ER_MALLOC, "(cmd1_join)"));
		if (!access(infos->cmd1_join, F_OK | X_OK))
			break ;
		free(infos->cmd1_join);
		infos->cmd1_join = NULL;
		i++;
	}
	if (!infos->paths[i])
		return (ft_cleanup(infos, FR_PARS_CMD1));
	return (0);
}

int	ft_pars_global(int argc, char **argv, char **envp, t_utils *infos)
{
	if (!ft_open_infile(argv[1], infos))
		if (!ft_pars_envp(envp, infos))
			return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:32:25 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/19 14:18:37 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_open_infile(const char *file, t_utils *infos)
{
	infos->fdin = open(file, O_RDONLY);
	if (infos->fdin == -1)
	{
		ft_access_error(file, __FILE__, __LINE__);
		return (1);
	}
	return (0);
}

int	ft_get_path(char **envp, int *i)
{
	char	*path;

	while (envp[*i])
	{
		path = ft_strnstr(envp[*i], "PATH=", 5);
		if (path)
			break ;
		(*i)++;
	}
	if (!envp[*i])
	{
		ft_error(ER_ENVP, __FILE__, __LINE__);
		return (1);
	}
	return (0);
}

int	ft_pars_envp(char **envp, t_utils *infos)
{
	char	*path;
	int		i;

	i = 0;
	if (ft_get_path(envp, &i))
		return (1);
	path = ft_strdup(envp[i] + 5);
	if (!path)
	{
		ft_error(ER_MALLOC, __FILE__, __LINE__);
		return (1);
	}
	infos->paths = ft_split(path, ':');
	free(path);
	if (!infos->paths)
	{
		ft_error(ER_MALLOC, __FILE__, __LINE__);
		return (1);
	}
	return (0);
}

int	ft_open_outfile(const char *file, t_utils *infos)
{
	infos->fdout = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (infos->fdout == -1)
	{
		ft_access_error(file, __FILE__, __LINE__);
		return (1);
	}
	return (0);
}

int	ft_pars_global(int argc, char **argv, char **envp, t_utils *infos)
{
	if (!ft_open_infile(argv[1], infos))
		if (!ft_open_outfile(argv[argc - 1], infos))
			if (!ft_pars_envp(envp, infos))
				return (0);
	return (1);
}

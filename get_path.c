/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:08:10 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/19 11:17:00 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pipex.h>

int	ft_get_pathname(t_list *cmds, char *path, char *cmdash)
{
	cmds->pathname = ft_strjoin(path, cmdash);
	if (!cmds->pathname)
	{
		ft_error(ER_JOIN, __FILE__, __LINE__);
		return (1);
	}
	return (0);
}

int	ft_fill_pathnames(t_utils *infos, t_list *cmds)
{
	char	*cmdash;
	int		i;

	i = 0;
	cmdash = ft_strjoin("/", cmds->content[i]);
	if (!cmdash)
	{
		ft_error(ER_MALLOC, __FILE__, __LINE__);
		return (1);
	}
	while (infos->paths[i])
	{
		if (ft_get_pathname(cmds, infos->paths[i], cmdash))
			return (1);
		if (access(cmds->pathname, X_OK) == 0)
			break ;
		free(cmds->pathname);
		i++;
	}
	if (!infos->paths[i])
		cmds->pathname = NULL;
	free(cmdash);
	return (0);
}

int	ft_fill_pathnames_all(t_utils *infos, t_list **cmds)
{
	int		i;
	t_list	*temp;

	temp = *cmds;
	while (temp)
	{
		if (ft_fill_pathnames(infos, temp))
			return (1);
		temp = temp->next;
	}
	i = 0;
	while (infos->paths[i])
	{
		free(infos->paths[i]);
		i++;
	}
	free(infos->paths);
	return (0);
}

int	ft_pars_init_cmd(t_utils *infos, char **argv, int argc, t_list **cmds)
{
	int		i;
	char	**content;
	t_list	*new;

	i = 2;
	while (i < argc - 1)
	{
		content = ft_split(argv[i], ' ');
		if (!content)
		{
			ft_error(ER_MALLOC, __FILE__, __LINE__);
			return (1);
		}
		new = ft_lstnew(content);
		if (!new)
		{
			ft_error(ER_MALLOC, __FILE__, __LINE__);
			return (1);
		}
		ft_lstadd_back(cmds, new);
		i++;
	}
	infos->cmd_count = i - 2;
	return (0);
}

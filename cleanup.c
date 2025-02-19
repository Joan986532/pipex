/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:03:41 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/19 09:26:52 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**ft_freesplit_pipex(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	return (NULL);
}

int	ft_clean_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

void	ft_lstclear_pipex(t_list **cmds)
{
	t_list	*tmp;
	int		i;

	if (!*cmds)
		return ;
	while (*cmds)
	{
		i = 0;
		tmp = (*cmds)->next;
		if ((*cmds)->pathname)
			free((*cmds)->pathname);
		if ((*cmds)->content)
		{
			while ((*cmds)->content[i])
			{
				free((*cmds)->content[i]);
				i++;
			}
			free((*cmds)->content);
		}
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = NULL;
}

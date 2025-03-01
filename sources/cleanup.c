/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:03:41 by jnauroy           #+#    #+#             */
/*   Updated: 2025/03/01 14:23:45 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <headers/pipex.h>

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

void	ft_clean_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
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
		free((*cmds)->pathname);
		while ((*cmds)->content[i])
		{
			free((*cmds)->content[i]);
			i++;
		}
		free((*cmds)->content);
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:59:45 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/06 16:27:26 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> //open, O_RDONLY
# include <stdio.h> //printf
# include <string.h>
# include "Libft_pipex/libft.h"

//error codes
# define ER_MALLOC 1
# define ER_F_OK 2
# define ER_WRX_OK 3
# define ER_CMD 4

//cleanup codes
# define FR_ALL 0
# define FR_PARS_CMD1 1

typedef struct s_utils //1 all
{
	int		fd;
	char	**paths;		//2
	char	*cmd1_join;		//3
	char	**cmd1_split;	//4
}		t_utils;

int		main(int argc, char **argv, char **envp);
int		ft_open_infile(const char *infile, t_utils *infos);
int		ft_error(int error, char *spot);
int		ft_access_error(const char *file);
int		ft_cleanup(t_utils *infos, int code);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:59:45 by jnauroy           #+#    #+#             */
/*   Updated: 2025/03/01 15:22:16 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> //open, O_RDONLY
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include "Libft_pipex/libft.h"
# include "ft_printf/ft_printf.h"

/* typedef enum errors */
/* { */
/* 	ER_MALLOC, */
/* 	ER_F_OK, */
/* 	ER_WRX_OK, */
/* 	ER_CMD, */
/* 	ER_ENVP, */
/* 	ER_PIPE, */
/* 	ER_JOIN, */
/* }	t_error; */

typedef struct s_utils
{
	int		fdin;
	int		fdout;
	int		tmp;
	int		pid;
	int		in;
	int		out;
	int		cmd_count;
	char	**paths;
	int		exitno;
	int		numerror;
	int		i;
}		t_utils;

//pipex.c
int		main(int argc, char **argv, char **envp);

//pipex_utils.c
int		ft_error(char *file, int line);
int		ft_access_error(const char *file, char *f, int l);
void	ft_get_cmds(t_list **tmp, t_utils *infos);
void	ft_wait_pid(t_utils *infos);
void	ft_close(t_utils *infos);

//cleanup.c
char	**ft_freesplit_pipex(char **str);
void	ft_lstclear_pipex(t_list **cmds);
void	ft_clean_tab(char **tab);

//pipex_program.c
int		ft_init_pipe(t_utils *infos, int *fd);
int		ft_pipex_prg(char **argv, t_utils *infos, t_list **cmds, char **envp);
int		ft_exe_pipex(t_utils *infos, t_list **cmds, t_list *tmp, char **envp);
void	ft_child_process(int *fd, t_utils *infos, t_list *cmds, char **envp);
void	ft_init_child(t_utils *infos);

//get_path.c
int		ft_fill_pathnames(t_utils *infos, t_list *tmp);
int		ft_fill_pathnames_all(t_utils *infos, t_list **cmds);
int		ft_get_pathname(t_list *cmds, char *path, char *cmdash);
int		ft_pars_init_cmd(t_utils *infos, char **argv, int argc, t_list **cmds);
void	ft_cmd_not_found(t_list *cmds, char *cmdash);

//parsing_files.c
int		ft_open_infile(const char *file, t_utils *infos);
int		ft_pars_envp(char **envp, t_utils *infos);
int		ft_open_outfile(const char *file, t_utils *infos);
int		ft_pars_global(int argc, char **argv, char **envp, t_utils *infos);
#endif

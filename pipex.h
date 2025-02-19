/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:59:45 by jnauroy           #+#    #+#             */
/*   Updated: 2025/02/19 15:38:00 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> //open, O_RDONLY
# include <stdio.h> //printf
# include <sys/wait.h>
# include <string.h>
# include <unistd.h>
# include "Libft_pipex/libft.h"
# include "ft_printf/ft_printf.h"

# define IN 1
# define OUT 0

//error codes
/* # define ER_MALLOC 1 */
/* # define ER_F_OK 2 */
/* # define ER_WRX_OK 3 */
/* # define ER_CMD 4 */
/* # define ER_PIPE 5 */

//cleanup codes
# define FR_ALL 0
# define FR_PARS_CMD1 1
# define FR_PARS_CMD2 2

typedef enum errors
{
	ER_MALLOC,
	ER_F_OK,
	ER_WRX_OK,
	ER_CMD,
	ER_ENVP,
	ER_PIPE,
	ER_JOIN,
}	t_error;

typedef struct s_utils
{
	int		fdin;
	int		fdout;
	int		cmd_count;
	char	**paths;
	int		pipe_out;
}		t_utils;

//pipex.c
int		main(int argc, char **argv, char **envp);

//parsing_files.c
int		ft_open_infile(const char *file, t_utils *infos);
int		ft_pars_envp(char **envp, t_utils *infos);
int		ft_open_outfile(const char *file, t_utils *infos);
int		ft_pars_global(int argc, char **argv, char **envp, t_utils *infos);

//error_functions.c
int		ft_error(t_error a, char *file, int line);
int		ft_access_error(const char *file, char *f, int l);

//cleanup.c
char	**ft_freesplit_pipex(char **str);
void	ft_lstclear_pipex(t_list **cmds);
int		ft_clean_tab(char **tab);

//pipex_program.c
int		ft_child_process(int *fd, t_list *cmds, char **envp);
int		ft_parent_process(int *fd);
int		ft_init_pipe(int *pid, int *fd);
int		ft_pipex_prg(t_utils *infos, t_list **cmds, char **envp, int *i);
int		ft_exe_pipex(t_list **cmds, char **envp, int *i);

//get_path.c
int		ft_fill_pathnames(t_utils *infos, t_list *cmds);
int		ft_fill_pathnames_all(t_utils *infos, t_list **cmds);
int		ft_get_pathname(t_list *cmds, char *path, char *cmdash);
int		ft_pars_init_cmd(t_utils *infos, char **argv, int argc, t_list **cmds);

//outfile_process.c
int		ft_exe_outfile(t_utils *infos, t_list **cmds, char **envp, int *i);
int		ft_outfile_process(int fd_out, t_list *cmds, char **envp);
void	ft_get_cmds(t_list *tmp, t_list **cmd, int *i);
#endif

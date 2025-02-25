/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/25 19:31:38 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define WRITE_END 1
# define READ_END 0

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	*file1;
	char	*file2;
	int		fd[2];
}			t_pipex;

// pipex_check_errors.c
void		check_args(int arc);
void		check_fd(int fd);
void		check_fork(pid_t p, t_pipex *pipex);

// pipex_execute.c
void		execute_cmd(t_pipex *pipex, char **cmd, char **envp);

// pipex_utils.c
void		fill_pipex(t_pipex *pipex, char *file2, char *cmd1, char *cmd2);
void		free_pipex(t_pipex *pipex, int exit_fd);
void		free_args(t_pipex *pipex, char **args, int yes);
int			create_file(char *name, t_pipex *pipex);

#endif
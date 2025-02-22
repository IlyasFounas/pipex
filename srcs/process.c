/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:43:23 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/22 18:35:11 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_cmd(t_pipex *pipex, char *file, char **cmd, char **envp)
{
	char	**args;
	
	printf("ÁSDKMVAE[KB]\n");
	args = fill_args(pipex, file, cmd);
	execve(cmd[0], args, envp);
	free_args(pipex, args, 0);
}

static void	execute_cmd2(t_pipex *pipex, char *file, char **cmd, char **envp)
{
	char	**args;
	
	printf("uuuuuuuuu\n");
	args = fill_args(pipex, file, cmd);
	execve(cmd[0], args, envp);
	free_args(pipex, args, 0);
}

void	child_process(t_pipex *pipex, pid_t p, char **envp)
{
	if (p == 0)
	{
		dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
		close(pipex->fd[READ_END]);
		close(pipex->fd[WRITE_END]);
		execute_cmd(pipex, pipex->file1, pipex->cmd1, envp);
		free_pipex(pipex, 0);
	}
}

void	child_process_bis(t_pipex *pipex, pid_t p, char **envp)
{
	if (p == 0)
	{
		dup2(pipex->fd[READ_END], STDIN_FILENO);
		close(pipex->fd[WRITE_END]);
		close(pipex->fd[READ_END]);
		execute_cmd2(pipex, pipex->file2, pipex->cmd2, envp);
		free_pipex(pipex, 0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:59:16 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/06 13:45:54 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(t_pipex *pipex, char **envp)
{
	if (pipex->fdin == -2)
	{
		ft_putstr_fd("permission denied: ", 2);
		ft_putstr_fd(pipex->file1, 2);
		ft_putstr_fd("\n", 2);
		free_pipex(pipex, 1);
	}
	else if (pipex->fdin == -3)
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(pipex->file1, 2);
		ft_putstr_fd("\n", 2);
		free_pipex(pipex, 1);
	}
	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
		free_pipex(pipex, 1);
	if (dup2(pipex->fdin, STDIN_FILENO) == -1)
		free_pipex(pipex, 1);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->fdout);
	close(pipex->fdin);
	execute_cmd(pipex, pipex->cmd1, envp, 1);
}

static void	child_process_bis(t_pipex *pipex, char **envp)
{
	if (pipex->pid[1] == 0)
	{
		if (pipex->fdout == -2)
		{
			ft_putstr_fd("permission denied: ", 2);
			ft_putstr_fd(pipex->file2, 2);
			ft_putstr_fd("\n", 2);
			free_pipex(pipex, 1);
		}
		if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
			free_pipex(pipex, 1);
		if (dup2(pipex->fdout, STDOUT_FILENO) == -1)
			free_pipex(pipex, 1);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		close(pipex->fdout);
		close(pipex->fdin);
	}
	execute_cmd(pipex, pipex->cmd2, envp, 2);
}

int	main(int arc, char **arv, char **envp)
{
	t_pipex	pipex;

	check_args(arc);
	ft_memset(&pipex, 0, sizeof(t_pipex));
	pipex.file1 = ft_strdup(arv[1]);
	if (!pipex.file1)
		free_pipex(&pipex, 1);
	fill_pipex(&pipex, arv[4], arv[2], arv[3]);
	if (pipex.fdout == -2)
		pipex.exit_fd = 1;
	if (pipe(pipex.fd) == -1)
		free_pipex(&pipex, 1);
	pipex.pid[0] = fork();
	check_fork(pipex.pid[0], &pipex);
	if (pipex.pid[0] == 0)
		child_process(&pipex, envp);
	pipex.pid[1] = fork();
	check_fork(pipex.pid[1], &pipex);
	child_process_bis(&pipex, envp);
	free_pipex(&pipex, pipex.exit_fd);
	return (pipex.exit_fd);
}

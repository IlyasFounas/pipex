/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/27 14:54:01 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(t_pipex *pipex, char **envp)
{
	if (pipex->fdout == -2)
		free_pipex(pipex, 1);
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->fdin, STDIN_FILENO);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->fdout);
	close(pipex->fdin);
	execute_cmd(pipex, pipex->cmd1, envp);
	free_pipex(pipex, 0);
}

static void	child_process_bis(t_pipex *pipex, char **envp)
{
	if (pipex->fdout == -2)
		free_pipex(pipex, 1);
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->fdout, STDOUT_FILENO);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->fdout);
	close(pipex->fdin);
	execute_cmd(pipex, pipex->cmd2, envp);
	free_pipex(pipex, 0);
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
	if (pipe(pipex.fd) == -1)
		free_pipex(&pipex, 1);
	pipex.pid[0] = fork();
	check_fork(pipex.pid[0], &pipex);
	if (pipex.pid[0] == 0)
		child_process(&pipex, envp);
	pipex.pid[1] = fork();
	check_fork(pipex.pid[1], &pipex);
	if (pipex.pid[1] == 0)
		child_process_bis(&pipex, envp);
	free_pipex(&pipex, 0);
	return (0);
}

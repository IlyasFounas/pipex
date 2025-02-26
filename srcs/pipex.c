/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/26 11:25:35 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(t_pipex *pipex, pid_t p, char **envp)
{
	if (p == 0)
	{
		pipex->fdin = open(pipex->file1, O_RDONLY, 0777);
		check_fd(pipex->fdin, pipex);
		dup2(pipex->fd[1], STDOUT_FILENO);
		dup2(pipex->fdin, STDIN_FILENO);
		close(pipex->fd[0]);
		execute_cmd(pipex, pipex->cmd1, envp);
		free_pipex(pipex, 0);
	}
}

static void	parent_process_bis(t_pipex *pipex, char **envp)
{
	pipex->fdout = create_file(pipex->file2, pipex);
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->fdout, STDOUT_FILENO);
	close(pipex->fd[1]);
	execute_cmd(pipex, pipex->cmd2, envp);
	free_pipex(pipex, 0);
}

int	main(int arc, char **arv, char **envp)
{
	pid_t	p;
	t_pipex	pipex;

	check_args(arc);
	ft_memset(&pipex, 0, sizeof(t_pipex));
	fill_pipex(&pipex, arv[4], arv[2], arv[3]);
	if (pipe(pipex.fd) == -1)
		free_pipex(&pipex, 1);
	p = fork();
	check_fork(p, &pipex);
	pipex.file1 = ft_strdup(arv[1]);
	if (!pipex.file1)
		free_pipex(&pipex, 1);
	if (p == 0)
		child_process(&pipex, p, envp);
	waitpid(p, NULL, 0);
	close(pipex.fdout);
	close(pipex.fdin);
	parent_process_bis(&pipex, envp);
	free_pipex(&pipex, 0);
	return (0);
}

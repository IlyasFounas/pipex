/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/25 20:00:02 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(t_pipex *pipex, pid_t p, char **envp)
{
	int	filein;

	if (p == 0)
	{
		filein = open(pipex->file1, O_RDONLY, 0777);
		if (filein == -1)
			free_pipex(pipex, 0);
		dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
		dup2(filein, STDIN_FILENO);
		close(pipex->fd[READ_END]);
		execute_cmd(pipex, pipex->cmd1, envp);
		free_pipex(pipex, 0);
	}
}

static void	parent_process_bis(t_pipex *pipex, char **envp)
{
	int	fileout;

	fileout = create_file(pipex->file2, pipex);
	dup2(pipex->fd[READ_END], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(pipex->fd[WRITE_END]);
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
	pipe(pipex.fd);
	p = fork();
	check_fork(p, &pipex);
	pipex.file1 = ft_strdup(arv[1]);
	if (!pipex.file1)
		free_pipex(&pipex, 1);
	if (p == 0)
		child_process(&pipex, p, envp);
	waitpid(p, NULL, 0);
	parent_process_bis(&pipex, envp);
	free_pipex(&pipex, 0);
	return (0);
}

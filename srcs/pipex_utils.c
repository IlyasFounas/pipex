/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:17:45 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/06 13:59:34 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmd(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}

static void	close_fds(t_pipex *pipex)
{
	if (pipex->fd[0] != -1)
		close(pipex->fd[0]);
	if (pipex->fd[1] != -1)
		close(pipex->fd[1]);
	if (pipex->fdout != -1)
		close(pipex->fdout);
	if (pipex->fdin != -1)
		close(pipex->fdin);
}

void	free_pipex(t_pipex *pipex, int exit_fd)
{
	int	status;

	status = 0;
	if (pipex->file1)
		free(pipex->file1);
	if (pipex->file2)
		free(pipex->file2);
	if (pipex->cmd1)
		free_cmd(pipex->cmd1);
	if (pipex->cmd2)
		free_cmd(pipex->cmd2);
	close_fds(pipex);
	if (waitpid(pipex->pid[0], &status, 0) == -1 && exit_fd != 127)
		exit(1);
	if (waitpid(pipex->pid[1], &status, 0) == -1 && exit_fd != 127)
		exit(1);
	if (WIFEXITED(status) && exit_fd != 127)
		exit(WEXITSTATUS(status));
	else if (WIFSIGNALED(status) && exit_fd != 127)
		exit(128 + WTERMSIG(status));
	exit(exit_fd);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	fill_pipex(t_pipex *pipex, char *file2, char *cmd1, char *cmd2)
{
	pipex->file2 = ft_strdup(file2);
	if (!pipex->file2)
		free_pipex(pipex, 1);
	pipex->cmd1 = ft_split(cmd1, ' ');
	if (!pipex->cmd1)
		free_pipex(pipex, 1);
	pipex->cmd2 = ft_split(cmd2, ' ');
	if (!pipex->cmd2)
		free_pipex(pipex, 1);
	if (access(pipex->file1, F_OK) != 0)
		pipex->fdin = -3;
	else if (access(pipex->file1, F_OK | R_OK) == 0)
	{
		pipex->fdin = open(pipex->file1, O_RDONLY, 0644);
		check_fd(pipex->fdin, pipex, 1);
	}
	else
		pipex->fdin = -2;
	if (access(pipex->file2, F_OK) != 0)
		pipex->fdout = open(pipex->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (access(pipex->file2, W_OK) == 0)
		pipex->fdout = open(pipex->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		pipex->fdout = -2;
	check_fd(pipex->fdout, pipex, 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:17:45 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/05 13:22:20 by ifounas          ###   ########.fr       */
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

void	free_pipex(t_pipex *pipex, int exit_fd)
{
	if (pipex->file1)
		free(pipex->file1);
	if (pipex->file2)
		free(pipex->file2);
	if (pipex->cmd1)
		free_cmd(pipex->cmd1);
	if (pipex->cmd2)
		free_cmd(pipex->cmd2);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->fdout);
	close(pipex->fdin);
	waitpid(pipex->pid[0], NULL, 0);
	waitpid(pipex->pid[1], NULL, 0);
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

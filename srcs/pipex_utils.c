/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:17:45 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/26 18:08:42 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipex(t_pipex *pipex, int exit_fd)
{
	int	i;

	i = -1;
	if (pipex->file1)
		free(pipex->file1);
	if (pipex->file2)
		free(pipex->file2);
	if (pipex->cmd1)
		while (pipex->cmd1[++i])
			free(pipex->cmd1[i]);
	i = -1;
	if (pipex->cmd2)
		while (pipex->cmd2[++i])
			free(pipex->cmd2[i]);
	free(pipex->cmd1);
	free(pipex->cmd2);
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
	int	i;

	i = 0;
	pipex->file2 = ft_strdup(file2);
	if (!pipex->file2)
		free_pipex(pipex, 1);
	pipex->cmd1 = ft_split(cmd1, ' ');
	if (!pipex->cmd1)
		free_pipex(pipex, 1);
	pipex->cmd2 = ft_split(cmd2, ' ');
	if (!pipex->cmd2)
		free_pipex(pipex, 1);
	pipex->fdin = open(pipex->file1, O_RDONLY, 0777);
	check_fd(pipex->fdin, pipex, 1);
	pipex->fdout = open(pipex->file2, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	check_fd(pipex->fdout, pipex, 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:59:44 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/20 18:46:10 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_pipex *pipex, int exit_fd)
{
	int	i;

	i = -1;
	if (pipex->file1)
		free(pipex->file1);
	if (pipex->file2)
		free(pipex->file2);
	while (pipex->cmd1[++i])
		free(pipex->cmd1[i]);
	i = -1;
	while (pipex->cmd2[++i])
		free(pipex->cmd2[i]);
	free(pipex->cmd1);
	free(pipex->cmd2);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	exit(exit_fd);
}

void	check_args(int arc)
{
	if (arc != 5)
	{
		ft_putstr_fd("Error\nexemple : ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
}

void	check_fd(int fd)
{
	if (fd == -1)
	{
		ft_putstr_fd("Error\nPut a valid file", 2);
		close(fd);
		exit(1);
	}
}

void	check_fork(pid_t p, t_pipex *pipex)
{
	if (p < 0)
	{
		ft_putstr_fd("Error\nFork failed", 2);
		close_fd(pipex, 1);
	}
}

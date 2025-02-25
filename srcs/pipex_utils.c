/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:17:45 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/25 19:39:24 by ifounas          ###   ########.fr       */
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

void	free_args(t_pipex *pipex, char **args, int yes)
{
	int	y;

	y = -1;
	if (args)
		while (args[++y])
			free(args[y]);
	if (yes == 1)
		free_pipex(pipex, 1);
	return ;
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
}

int	create_file(char *name, t_pipex *pipex)
{
	int	fileout;
	
	fileout = open(name, O_RDWR | O_TRUNC);
	if (fileout == -1)
	{
		fileout = open(name, O_CREAT | O_RDWR, 0777);
		if (fileout == -1)
			free_pipex(pipex, 1);
	}
	return (fileout);
}

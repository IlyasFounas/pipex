/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:17:45 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/21 15:10:08 by ifounas          ###   ########.fr       */
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

void	print_infos(t_pipex pipex)
{
	int	i;

	i = -1;
	ft_printf("YOUR FILES : < %s | %s >", pipex.file1, pipex.file2);
	ft_printf("\nCMD1 : \n");
	while (pipex.cmd1[++i])
		ft_printf("- %s\n", pipex.cmd1[i]);
	i = -1;
	ft_printf("CMD2 : \n");
	while (pipex.cmd2[++i])
		ft_printf("- %s\n", pipex.cmd2[i]);
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

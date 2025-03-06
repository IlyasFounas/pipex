/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:59:44 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/06 13:45:12 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int arc)
{
	if (arc != 5)
	{
		ft_putstr_fd("how to run pipex : ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(1);
	}
}

void	check_fd(int fd, t_pipex *pipex, int file)
{
	if (fd == -1)
	{
		if (file == 1)
		{
			ft_putstr_fd("no such file or directory: ", 2);
			ft_putstr_fd(pipex->file1, 2);
			ft_putstr_fd("\n", 2);
		}
		else
		{
			ft_putstr_fd("no such file or directory: ", 2);
			ft_putstr_fd(pipex->file2, 2);
			ft_putstr_fd("\n", 2);
		}
		free_pipex(pipex, 1);
		exit(1);
	}
}

void	check_fork(pid_t p, t_pipex *pipex)
{
	if (p < 0)
	{
		ft_putstr_fd("new processus failed\n", 2);
		free_pipex(pipex, 1);
	}
}

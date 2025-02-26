/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:59:44 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/26 10:49:09 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int arc)
{
	if (arc != 5)
	{
		ft_putstr_fd("Error\nExemple : ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
}

void	check_fd(int fd, t_pipex *pipex)
{
	if (fd == -1)
	{
		ft_putstr_fd("Error\nPut a valid file", 2);
		free_pipex(pipex, 1);
		exit(1);
	}
}

void	check_fork(pid_t p, t_pipex *pipex)
{
	if (p < 0)
	{
		ft_putstr_fd("Error\nNew processus failed", 2);
		free_pipex(pipex, 1);
	}
}

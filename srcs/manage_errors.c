/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:59:44 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/15 17:52:36 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int arc)
{
	if (arc != 5)
	{
        perror("Error\nBad arguments");
		exit(1);
	}
}

void	check_fd(int fd)
{
	if (fd == -1)
	{
        perror("Error\nPut a valid file");
		close(fd);
		exit(1);
	}
}

void	check_fork(pid_t p, int *fd)
{
	if (p < 0)
	{
        perror("Error\nFork failed");
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
}

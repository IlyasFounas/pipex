/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/15 18:07:58 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_file(char *name, int *fd)
{

	fd[1] = open(name, O_RDWR | O_TRUNC);
	if (fd[1] == -1)
	{
		fd[1] = open(name, O_CREAT | O_RDWR , 0777);
		if (fd[1] == -1)
		{
			close(fd[0]);
			exit(1);
		}
	}
}

int	main(int arc, char **arv, char **envp)
{
	int		fd[2];
	pid_t	p;

	check_args(arc);
	fd[0] = open(arv[1], O_RDONLY);
	check_fd(fd[0]);
	create_file(arv[4], fd);
	p = fork();
	check_fork(p, fd);
	if (p == 0) {
        char *args[] = {arv[2], arv[1], NULL};
        execve(arv[2], args, envp);
        perror("execve");
    }
	close(fd[0]);
	close(fd[1]);
	return (0);
}

// < main.c cat | cat  > cpy.c
// ft_printf("cmd1 : %s\ncmd2 : %s\n", arv[2], arv[3]);
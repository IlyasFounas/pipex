/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/21 15:32:17 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_file(char *name, t_pipex *pipex)
{
	pipex->fd[1] = open(name, O_RDWR | O_TRUNC);
	if (pipex->fd[1] == -1)
	{
		pipex->fd[1] = open(name, O_CREAT | O_RDWR, 0777);
		if (pipex->fd[1] == -1)
			free_pipex(pipex, 1);
	}
}

void	execute_cmd1(char *file, char **cmd)
{
	int		p2[2];
	char	*args[] = {cmd[0], file, cmd[1], NULL};
	char	*res;

	res = ft_strjoin("/bin/", cmd[0]);
	if (!res)
		return ;
	if (pipe(p2) == -1)
		return ;
	p2[1] = execve(res, args, NULL);
	free(res);
}

int	main(int arc, char **arv, char **envp)
{
	pid_t	p;
	t_pipex	pipex;

	(void)envp;
	check_args(arc);
	ft_memset(&pipex, 0, sizeof(t_pipex));
	pipex.fd[0] = open(arv[1], O_RDONLY);
	check_fd(pipex.fd[0]);
	create_file(arv[4], &pipex);
	p = fork();
	check_fork(p, &pipex);
	pipex.file1 = ft_strdup(arv[1]);
	if (!pipex.file1)
		free_pipex(&pipex, 1);
	if (p == 0)
	{
		fill_pipex(&pipex, arv[4], arv[2], arv[3]);
		
		// print_infos(pipex);
		dup2(pipex.fd[1], 1);
		execute_cmd1(pipex.file1, pipex.cmd1);
		free_pipex(&pipex, 0);
	}
	else
		free(pipex.file1);
	return (0);
}
// < main.c cat | cat  > cpy.c
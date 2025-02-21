/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/21 18:33:37 by ifounas          ###   ########.fr       */
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

char	**fill_args(t_pipex *pipex, char *file, char **cmd)
{
	int		i;
	int		cmd_i;
	char	**args;

	i = 0;
	cmd_i = 0;
	while (cmd[i])
		i++;
	args = malloc((i + 2) * sizeof(char *));
	if (!args)
		free_pipex(pipex, 1);
	if (i == 1)
	{
		args[0] = ft_strdup(cmd[0]);
		if (!args[0])
			free_args(pipex, args, 1);
		args[1] = ft_strdup(file);
		if (!args[1])
			free_args(pipex, args, 1);
		args[2] = NULL;
		return (args);
	}
	i = 0;
	while (cmd[cmd_i])
	{
		if (i == 1)
			args[i] = ft_strdup(file);
		else
		{
			args[i] = ft_strdup(cmd[cmd_i]);
			cmd_i++;
		}
		if (!args[i])
			free_args(pipex, args, 1);
		i++;
	}
	args[i] = NULL;
	return (args);
}

void	execute_cmd1(t_pipex *pipex, char *file, char **cmd)
{
	char	**args;
	char	*res;

	args = fill_args(pipex, file, cmd);
	res = ft_strjoin("/bin/", cmd[0]);
	if (!res)
		return ;
	execve(res, args, NULL);
	free(res);
	free_args(pipex, args, 0);
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
		dup2(pipex.fd[1], 1);
		execute_cmd1(&pipex, pipex.file1, pipex.cmd1);
		free_pipex(&pipex, 0);
	}
	else
		free(pipex.file1);
	return (0);
}
// < main.c cat | cat  > cpy.c
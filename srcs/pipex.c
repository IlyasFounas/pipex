/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/22 18:35:23 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	main(int arc, char **arv, char **envp)
{
	pid_t	p;
	t_pipex	pipex;

	check_args(arc);
	ft_memset(&pipex, 0, sizeof(t_pipex));
	pipex.fd[0] = open(arv[1], O_RDONLY);
	check_fd(pipex.fd[0]);
	create_file(arv[4], &pipex);
	fill_pipex(&pipex, arv[4], arv[2], arv[3]);
	
	pipe(pipex.fd);
	p = fork();
	check_fork(p, &pipex);
	pipex.file1 = ft_strdup(arv[1]);
	if (!pipex.file1)
		free_pipex(&pipex, 1);
	if (p == 0)
		child_process(&pipex, p, envp);
	
	p = fork();
	check_fork(p, &pipex);
	if (p == 0)
		child_process_bis(&pipex, p, envp);
	return (0);
}

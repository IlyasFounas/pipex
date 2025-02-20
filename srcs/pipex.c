/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/20 18:52:01 by ifounas          ###   ########.fr       */
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
			close_fd(pipex, 1);
	}
}

void	execute_cmd1(char *file, char *cmd, char *params)
{
	int		p2[2];
	char	*args[] = {cmd, file, params, NULL};
	char	*res;

	res = ft_strjoin("/bin/", cmd);
	if (!res)
		return ;
	if (pipe(p2) == -1)
		return ;
	p2[1] = execve(res, args, NULL);
	free(res);
}

char	*find_params(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	if (cmd[i + 1] == '\0')
		return (NULL);
	return (&cmd[i + 1]);
}

char	**fill_params(t_pipex *pipex, char *cmd)
{
	char **args;

	args = ft_split(cmd, ' ');
	if (!args)
		close_fd(pipex, 1);
	return (args);
}

void	fill_t_pipex(t_pipex *pipex, char *file2, char *cmd1, char *cmd2)
{
	int	i;

	i = 0;
	pipex->file2 = ft_strdup(file2);
	if (!pipex->file2)
		close_fd(pipex, 1);
	pipex->cmd1 = fill_params(pipex, cmd1);
	pipex->cmd2 = fill_params(pipex, cmd2);
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
		close_fd(&pipex, 1);
	if (p == 0)
	{
		fill_t_pipex(&pipex, arv[4], arv[2], arv[3]);
		print_infos(pipex);
		close_fd(&pipex, 0);
	}
	else
		free(pipex.file1);
	return (0);
}

// < main.c cat | cat  > cpy.c
// ft_printf("cmd1 : %s\ncmd2 : %s\n", arv[2], arv[3]);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:43:23 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/05 17:33:23 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*return_path(char **tab, char *cmd)
{
	char	*path;
	char	*res;
	int		i;

	i = -1;
	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (tab[++i])
	{
		res = ft_strjoin(tab[i], "/");
		if (!res)
			return (NULL);
		path = ft_strjoin(res, cmd);
		if (!path)
			return (free(res), NULL);
		if (access(path, X_OK) == 0)
			return (free(res), path);
		free(res);
		free(path);
	}
	return (NULL);
}

static char	*return_right_path(char **envp, char *cmd)
{
	char	**tab;
	char	*path;
	int		i;
	int		yes;

	yes = 0;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			yes++;
			break ;
		}
	}
	if (yes == 0)
		return (NULL);
	tab = ft_split(envp[i] + 5, ':');
	if (!tab)
		return (NULL);
	path = return_path(tab, cmd);
	return (free_tab(tab), path);
}

void	execute_cmd(t_pipex *pipex, char **cmd, char **envp, int p)
{
	char	*path;

	path = return_right_path(envp, cmd[0]);
	if (pipex->pid[1] == 0)
	{
		if (!path)
		{
			ft_putstr_fd("command not found: ", 2);
			ft_putstr_fd(cmd[0], 2);
			ft_putstr_fd("\n", 2);
			free_pipex(pipex, 127);
		}
		execve(path, cmd, envp);
		free(path);
		free_pipex(pipex, 1);
	}
	if (!path && p == 2)
		pipex->exit_fd = 127;
	else
		free(path);
}

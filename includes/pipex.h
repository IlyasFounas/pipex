/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/20 18:25:11 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	*file1;
	char	*file2;
	int		fd[2];
}			t_pipex;

// check_errors.c
void		check_args(int arc);
void		check_fd(int fd);
void		check_fork(pid_t p, t_pipex *pipex);
void		close_fd(t_pipex *pipex, int exit_fd);

// pipex_utils.c
void		print_infos(t_pipex pipex);

#endif
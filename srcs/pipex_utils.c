/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:17:45 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/20 18:18:36 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_infos(t_pipex pipex)
{
	int	i;

	i = -1;
	ft_printf("YOUR FILES : < %s | %s >", pipex.file1, pipex.file2);
	ft_printf("\nCMD1 : \n");
	while (pipex.cmd1[++i])
		ft_printf("- %s\n", pipex.cmd1[i]);
	i = -1;
	ft_printf("CMD2 : \n");
	while (pipex.cmd2[++i])
		ft_printf("- %s\n", pipex.cmd2[i]);
}

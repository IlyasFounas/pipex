/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:40:35 by ifounas           #+#    #+#             */
/*   Updated: 2024/12/16 15:54:33 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *f, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n, int *counter);

#endif
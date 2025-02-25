/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:40:35 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/24 15:07:12 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *f, ...);
int		ft_putchar_printf(char c);
int		ft_putstr_printf(char *s);
size_t	ft_strlen_printf(const char *s);
void	ft_putnbr_printf(int n, int *counter);

#endif
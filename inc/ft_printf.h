/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:48:23 by marvin            #+#    #+#             */
/*   Updated: 2023/11/12 20:35:48 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int num);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned long n, int uppercase);

#endif

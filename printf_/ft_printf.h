/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:01:32 by ikrozas           #+#    #+#             */
/*   Updated: 2025/06/18 11:03:05 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

int		cases(char format, va_list args);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		ft_printhex(unsigned int num, int uppercase);
int		ft_printptr(void *ptr);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printuint(unsigned int n);

#endif

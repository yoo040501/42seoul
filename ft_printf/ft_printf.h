/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:07:40 by dongeunk          #+#    #+#             */
/*   Updated: 2023/11/27 16:05:43 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	pf_putstr(char *word);
int	pf_putchr(int n);
int	pf_putint(int n, int ret);
int	pf_putuint(unsigned int n, int ret);
int	pf_puthex(unsigned int n, char flag, int ret);
int	pf_putptr(unsigned long n, int ret);
#endif

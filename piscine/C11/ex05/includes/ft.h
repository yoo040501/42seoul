/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:17:50 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/14 15:47:40 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# define FALSE 0
# define TRUE 1

typedef int	t_bool;

void	ft_do_op(char **av);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_cal(int a, int b, int i);
int		ft_get_op(char *av, char *op);
t_bool	ft_check_op(char *op);
int		ft_getint(char *str, int i, int ret);

#endif

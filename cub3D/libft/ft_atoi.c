/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:16:50 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/18 14:10:24 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str);
static int	ft_getint(char *s, int si);

int	ft_atoi(const char *str)
{
	int		si;
	int		ret;
	int		i;
	char	*s;

	s = (char *)str;
	si = 1;
	i = -1;
	while (str[++i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 9 && str[i] <= 13)))
			return (-1);
	}
	while ((*s == ' ') || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			si *= -1;
		s++;
	}
	ret = ft_getint(s, si);
	return (ret * si);
}

static int	ft_getint(char *s, int si)
{
	unsigned long	ret;

	ret = 0;
	while (*s >= '0' && *s <= '9')
	{
		ret = ret * 10 + *(s++) - '0';
		if ((si == 1) && ret > 9223372036854775807)
			return (-1);
		if ((si == -1) && ret > 9223372036854775808U)
			return (0);
	}
	if (ret > 2147483647)
		return (-1);
	return (ret);
}

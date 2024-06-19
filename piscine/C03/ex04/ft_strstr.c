/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:39:08 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/02 21:31:52 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	l_s;
	int	l_t;

	l_s = 0;
	if (!*str && !*to_find)
		return (str);
	while (*(str + l_s))
	{
		l_t = 0;
		while (*(to_find + l_t) && (*(str + l_s + l_t) == *(to_find + l_t)))
		{
			l_t++;
		}	
		if (*(to_find + l_t) == '\0')
			return (str + l_s);
		l_s++;
	}
	return ((void *)0);
}

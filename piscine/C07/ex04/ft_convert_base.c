/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:46:37 by dongeunk          #+#    #+#             */
/*   Updated: 2023/09/13 12:41:14 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_atoi_base(char *str, char *base);
int		ft_change_nbr(char *str, char *base_from, int l_s, int l_b);
char	*ft_putnbr_base(int nbr, char *base);
void	ft_change_base(int nbr, char *base, char *word, int i);
int		ft_get_len(char *base);
int		ft_check_base(char *base, int i, int first);
int		ft_check_str(char *str, int *l_s);
int		ft_num_len(int nbr, int len);

/*#include <stdio.h>
int	main(void)
{
	char *nbr = "  +-+-a";
	char *base_from = "0123456789abcdf";
	char *base_to = "0123456789";
	char *str;
	str = ft_convert_base(nbr, base_from, base_to);
	printf("%s\n",str);
}*/
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*word;

	if (ft_check_base(base_from, 0, 0) == 0
		|| ft_check_base(base_to, 0, 0) == 0)
	{
		return (0);
	}
	else
	{
		num = ft_atoi_base(nbr, base_from);
		word = ft_putnbr_base(num, base_to);
	}
	return (word);
}

int	ft_atoi_base(char *str, char *base)
{
	int	l_b;
	int	l_s;
	int	sign;

	l_b = 0;
	l_s = 0;
	sign = ft_check_str(str, &l_s);
	l_b = ft_get_len(base);
	return (ft_change_nbr(str, base, l_s, l_b) * sign);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char	*word;
	int		l_b;
	int		num_len;

	l_b = ft_get_len(base);
	num_len = ft_num_len(nbr, l_b);
	word = (char *)malloc(sizeof(char) * (num_len + 1));
	ft_change_base(nbr, base, word, num_len - 1);
	word[num_len] = 0;
	return (word);
}

void	ft_change_base(int nbr, char *base, char *word, int i)
{
	unsigned int	n;
	int				len;

	len = ft_get_len(base);
	n = (unsigned int)nbr;
	if (nbr < 0)
	{
		n = (unsigned int)(nbr * -1);
		word[0] = '-';
	}
	if (n >= (unsigned int)len)
	{	
		ft_change_base(n / len, base, word, i - 1);
		word[i] = base[n % len];
	}
	else
	{
		word[i] = base[n];
	}
}

int	ft_change_nbr(char *str, char *base, int l_s, int l_b)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[l_s])
	{
		i = 0;
		while (base[i])
		{
			if (base[i] == str[l_s])
				break ;
			i++;
		}
		if (i >= l_b)
			break ;
		ret *= l_b;
		ret += i;
		l_s++;
	}
	return (ret);
}

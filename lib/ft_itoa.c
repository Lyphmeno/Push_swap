/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:33:18 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/06 17:05:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_get_size(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		nb;
	int		size;
	char	*str;

	nb = n;
	if (nb < 0)
		nb *= -1;
	size = ft_get_size(nb);
	i = size - 1;
	if (ft_negative(n) == 1)
		i = size;
	str = (char *)ft_calloc(sizeof(char), (size + ft_negative(n) + 1));
	while (i >= 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	if (ft_negative(n) == 1)
		str[0] = '-';
	return (str);
}

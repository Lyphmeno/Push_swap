/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:02:28 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/26 16:25:28 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *s, t_data *data)
{
	int		i;
	long	x;
	long	sign;

	i = 0;
	x = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]) == 1)
	{
		x = 10 * x + s[i] - '0';
		i++;
	}
	if ((x > 2147483647 && sign == 1) || (x > 2147483648 && sign == -1))
		data->res = 1;
	x *= sign;
	return (x);
}

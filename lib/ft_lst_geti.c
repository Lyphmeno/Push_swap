/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_geti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:27:25 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/20 21:09:47 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_geti(t_list *list, int value)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->value == value)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

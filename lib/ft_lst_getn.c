/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:53:50 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/16 19:01:28 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_getn(t_list *list, int index)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp != NULL)
	{
		if (i == index)
			return (tmp->value);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

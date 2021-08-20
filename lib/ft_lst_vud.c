/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_vud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:09:32 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/20 12:34:02 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_vup(t_data *data)
{
	t_list	*atmp;
	int		bvalue;
	int		res;

	atmp = data->alist;
	bvalue = data->blist->value;
	res = ft_lst_max(data->alist);
	while (atmp != NULL)
	{
		if (atmp->value > bvalue && atmp->value < res)
			res = atmp->value;
		atmp = atmp->next;
	}
	return (res);
}

int	ft_lst_vdown(t_data *data)
{
	t_list	*atmp;
	int		bvalue;
	int		res;

	atmp = data->alist;
	bvalue = data->blist->value;
	res = ft_lst_min(data->alist);
	while (atmp != NULL)
	{
		if (atmp->value < bvalue && atmp->value > res)
			res = atmp->value;
		atmp = atmp->next;
	}
	return (res);
}

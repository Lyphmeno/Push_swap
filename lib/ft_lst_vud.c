/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_vud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:09:32 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/22 14:43:45 by hlevi            ###   ########.fr       */
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
	if (res < bvalue)
		res = ft_lst_min(data->alist);
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
	if (res > bvalue)
		res = ft_lst_max(data->alist);
	return (res);
}

int	ft_lst_vbup(t_data *data)
{
	t_list	*btmp;
	int		avalue;
	int		res;

	btmp = data->blist;
	avalue = data->alist->value;
	res = ft_lst_max(data->blist);
	while (btmp != NULL)
	{
		if (btmp->value > avalue && btmp->value < res)
			res = btmp->value;
		btmp = btmp->next;
	}
	if (res < avalue)
		res = ft_lst_min(data->blist);
	return (res);
}

int	ft_lst_vbdown(t_data *data)
{
	t_list	*btmp;
	int		avalue;
	int		res;

	btmp = data->blist;
	avalue = data->alist->value;
	res = ft_lst_min(data->blist);
	while (btmp != NULL)
	{
		if (btmp->value < avalue && btmp->value > res)
			res = btmp->value;
		btmp = btmp->next;
	}
	if (res > avalue)
		res = ft_lst_max(data->blist);
	return (res);
}

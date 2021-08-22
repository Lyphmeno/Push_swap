/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:42:34 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/22 15:10:51 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int		is_in_chunk(t_data *data, int value)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (data->chunks[data->ccount][i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	find_first(t_data *data)
{
	t_list *tmp;

	tmp = data->alist;
	while (tmp != NULL)
	{
		if (is_in_chunk(data, tmp->value) == 1)
		{
			data->hfirst = tmp->value;
			data->phfirst = ft_lst_geti(data->alist, data->hfirst);
			break;
		}
		tmp = tmp->next;
	}
	data->mfirst = data->phfirst;
}

void	find_last(t_data *data)
{
	t_list *tmp;
	int		count;

	tmp = data->alist;
	count = 0;
	while (tmp != NULL)
	{
		if (is_in_chunk(data, tmp->value) == 1)
		{
			if (count < data->size - data->ncount - 1)
				count++;
			else
			{
				data->hlast = tmp->value;
				data->phlast = ft_lst_geti(data->alist, data->hlast);
				data->ncount++;
			}
		}
		tmp = tmp->next;
	}
	data->mlast = ft_lst_length(data->alist) - data->phlast;
}

void	to_pushb(t_data *data)
{
	if (ft_lst_length(data->blist) > 1)
	{
		ft_lst_ex(data->blist, data);
		data->vdown = ft_lst_vbup(data);
		data->vup = ft_lst_vbdown(data);
		data->pvup = ft_lst_geti(data->blist, data->vup);
		data->pvdown = ft_lst_geti(data->blist, data->vdown);
		// printf("%d < %d < %d\n", data->vdown, data->alist->value, data->vup);
		// printf("%d - %d\n", data->pvdown, data->pvup);
		while (data->pvup != 0 && data->pvdown
			!= (ft_lst_length(data->blist) - 1))
		{
			if (data->pvup > ft_lst_length(data->blist) / 2)
				rrb(data);
			else
				rb(data);
			data->pvup = ft_lst_geti(data->blist, data->vup);
			data->pvdown = ft_lst_geti(data->blist, data->vdown);
		}
	}
	push(&data->alist, &data->blist, "pb\n");
}

void	solve_big(t_data *data, int size)
{
	int	tmp;
	data->size = size;
	get_chunks(data, data->size);
	while (data->alist)
	{
		tmp = data->ccount;
		data->ccount = ft_lst_length(data->blist) / size;
		if (data->ccount != tmp)
		{
			data->ncount = 0;
			tmp = data->ccount;
		}
		// printf("ccount = %d | ncount = %d\n", data->ccount, data->ncount);
		find_first(data);
		find_last(data);
		// printf("hfirst = %d (%d)\n", data->hfirst, data->phfirst);
		// printf("hlast = %d (%d)\n", data->hlast, data->phlast);
		// printf("mh = %d | ml = %d\n", data->mfirst, data->mlast);
		if (data->mfirst < data->mlast || data->mfirst == data->mlast)
			while (ft_lst_geti(data->alist, data->hfirst) != 0)
				ra(data);
		else
			while (ft_lst_geti(data->alist, data->hlast) != 0)
				rra(data);
		to_pushb(data);
		// print_change(data);
	}
	while (ft_lst_geti(data->blist, ft_lst_max(data->blist)) != 0)
		rrb(data);
	while (data->blist)
		push(&data->blist, &data->alist, "pa\n");
}
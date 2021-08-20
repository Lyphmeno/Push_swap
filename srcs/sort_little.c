/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:53:05 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/20 21:45:47 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	push_three(t_data *data, int a, int b, int c)
{
	if (a > b && a < c)
		sa(data);
	if (a > b && a > c && b > c)
	{
		sa(data);
		rra(data);
	}
	if (a > b && a > c && b < c)
		ra(data);
	if (a < b && a < c && b > c)
	{
		sa(data);
		ra(data);
	}
	if (a < b && a > c)
		rra(data);
}

void	get_three(t_data *data)
{
	int		a;
	int		b;
	int		c;

	a = ft_lst_getn(data->alist, 0);
	b = ft_lst_getn(data->alist, 1);
	c = ft_lst_getn(data->alist, 2);
	push_three(data, a, b, c);
}

void	solve_five(t_data *data)
{
	while (ft_lst_length(data->alist) > 3)
		push(&data->alist, &data->blist, "pb\n");
	get_three(data);
	while (data->blist)
	{
		ft_lst_ex(data->alist, data);
		data->vup = ft_lst_vup(data);
		data->vdown = ft_lst_vdown(data);
		data->pvup = ft_lst_geti(data->alist, data->vup);
		data->pvdown = ft_lst_geti(data->alist, data->vdown);
		while (data->pvup != 0 && data->pvdown
			!= (ft_lst_length(data->alist) - 1))
		{
			if (data->pvup > ft_lst_length(data->alist) / 2)
				rra(data);
			else
				ra(data);
			data->pvup = ft_lst_geti(data->alist, data->vup);
			data->pvdown = ft_lst_geti(data->alist, data->vdown);
		}
		push(&data->blist, &data->alist, "pa\n");
	}
	re_order(data);
}

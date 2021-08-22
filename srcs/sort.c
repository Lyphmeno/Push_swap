/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:32:31 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/22 12:47:11 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	re_order(t_data *data)
{
	ft_lst_ex(data->alist, data);
	data->pmin = ft_lst_geti(data->alist, data->min);
	while (check_lst_sort(data->alist) != 1)
	{
		if (data->pmin > (ft_lst_length(data->alist) / 2))
			rra(data);
		else
			ra(data);
	}
}

void	push_base(t_data *data)
{
	if (!check_lst_sort(data->alist))
	{
		if (ft_lst_length(data->alist) == 2)
			sa(data);
		if (ft_lst_length(data->alist) == 3)
			get_three(data);
		if (ft_lst_length(data->alist) > 3 && ft_lst_length(data->alist) < 30)
			solve_five(data);
		if (ft_lst_length(data->alist) > 29)
		{
			if (ft_lst_length(data->alist) < 500)
				solve_big(data, 20);
			else
				solve_big(data, 11);
		}
	}
}

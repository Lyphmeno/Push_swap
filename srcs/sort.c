/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:32:31 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/17 17:32:45 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	push_three(t_data *data, int a, int b, int c)
{
	if (a > b && a < c) // 2 1 3
		sa(data);
	if (a > b && a > c && b > c) // 3 2 1
	{
		sa(data);
		rra(data);
	}
	if (a > b && a > c && b < c) // 3 1 2
		ra(data);
	if (a < b && a < c && b > c) // 1 3 2
	{
		sa(data);
		ra(data);
	}
	if (a < b && a > c) // 2 3 1
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

// void	solve_four(t_list **alist, t_list **blist)
// {
// 	t_list	*tmp;

// 	tmp = *alist;
// 	while (tmp->value != )
// }

void	push_swap_less(t_data *data)
{
	if (ft_lst_length(data->alist) == 3)
		get_three(data);
	// if (ft_lst_length(*alist) == 4)
	// 	solve_four(alist, blist);
	// if (ft_lst_length(*alist) == 5)
	// 	solve_five(alist, blist);
}

void	push_base(t_data *data)
{
	if (!check_lst_sort(data->alist))
	{
		if (ft_lst_length(data->alist) == 2)
			sa(data);
		if (ft_lst_length(data->alist) < 6 && ft_lst_length(data->alist) > 2)
			push_swap_less(data);
	}
}

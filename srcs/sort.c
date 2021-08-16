/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:32:31 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/16 19:26:02 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	push_three(t_list **alist, int a, int b, int c)
{
	if (a > b && a < c) // 2 1 3
		sa(alist);
	if (a > b && a > c && b > c) // 3 2 1
	{
		sa(alist);
		rra(alist);
	}
	if (a > b && a > c && b < c) // 3 1 2
		ra(alist);
	if (a < b && a < c && b > c) // 1 3 2
	{
		sa(alist);
		ra(alist);
	}
	if (a < b && a > c) // 2 3 1
		rra(alist);
}

void	get_three(t_list **alist)
{
	int		a;
	int		b;
	int		c;

	a = ft_lst_getn(*alist, 0);
	b = ft_lst_getn(*alist, 1);
	c = ft_lst_getn(*alist, 2);
	push_three(alist, a, b, c);
}

void	push_swap(t_list **alist, t_list **blist)
{
	if (ft_lst_length(*alist) == 3)
		get_three(alist);
	(void)blist;
}

void	push_base(t_list **alist, t_list **blist)
{
	(void)blist;
	if (ft_lst_length(*alist) > 2 && !check_lst_sort(*alist))
		push_swap(alist, blist);
	if (ft_lst_length(*alist) == 2 && !check_lst_sort(*alist))
		sa(alist);
}

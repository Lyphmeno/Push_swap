/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_short.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:19:40 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/16 19:25:43 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	sa(t_list **list)
{
	swap(*list);
	ft_putstr_fd("sa\n", 0);
}

void	sb(t_list **list)
{
	swap(*list);
	ft_putstr_fd("sb\n", 0);
}

void	ra(t_list **list)
{
	rotate(list, ft_lst_length(*list));
	ft_putstr_fd("ra\n", 0);
}

void	rb(t_list **list)
{
	rotate(list, ft_lst_length(*list));
	ft_putstr_fd("rb\n", 0);
}

void	rr(t_list **alist, t_list **blist)
{
	rotate(alist, 1);
	rotate(blist, 1);
	ft_putstr_fd("rr\n", 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_short2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:32:35 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/10 14:36:18 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	rra(t_list **list)
{
	rotate(list, ft_lst_length(*list));
	ft_putstr_fd("rra\n", 0);
}

void	rrb(t_list **list)
{
	rotate(list, ft_lst_length(*list));
	ft_putstr_fd("rrb\n", 0);
}

void	rrr(t_list **alist, t_list **blist)
{
	rotate(alist, ft_lst_length(*alist));
	rotate(blist, ft_lst_length(*blist));
	ft_putstr_fd("rrr\n", 0);
}

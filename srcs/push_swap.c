/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:10:59 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/16 17:16:39 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	push_base(t_list **alist, t_list **blist)
{
	(void)blist;
	if (ft_lst_length(*alist) > 2 && !check_lst_sort(*alist))
		ft_putstr_fd("List longer than 2 and not sorted\n", 0);
	if (ft_lst_length(*alist) == 2 && !check_lst_sort(*alist))
		sa(alist);
}

void	print_change(t_list *alist, t_list *blist)
{
	ft_putstr_fd("alist = ", 0);
	ft_lst_print(alist);
	ft_putstr_fd("blist = ", 0);
	ft_lst_print(blist);
	ft_putstr_fd("\n", 0);
}

int	main(int argc, char **argv)
{
	t_list	*alist;
	t_list	*blist;
	t_data	*data;

	alist = NULL;
	blist = NULL;
	data = ft_calloc(sizeof(t_data), 1);
	if (argc < 2)
		ft_exit_code("Error\nNo arguments\n", 1);
	parsing_base(&alist, argc, argv);
	check_dup(alist);
	print_change(alist, blist);
	push_base(&alist, &blist);
	print_change(alist, blist);
	ft_lst_ex(alist, data);
	printf("min = %d\nmid = %d\nmax = %d\n", data->min, data->mid, data->max);
	check_done(alist, blist);
	ft_lst_free(alist);
	ft_lst_free(blist);
	free(data);
	return (0);
}

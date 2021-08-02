/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:10:59 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/02 17:25:41 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	parsing_base(t_list **alist, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("%d\n", ft_atoi(argv[i]));
		*alist = ft_lst_add_back(*alist, ft_atoi(argv[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*alist;

	alist = NULL;
	if (argc < 2)
		exit(ft_putstr_fd("Error\nNo arguments\n", 0));
	parsing_base(&alist, argc, argv);
	ft_putstr_fd("List length = ", 0);
	ft_putstr_fd(ft_itoa(ft_lst_length(alist)), 0);
	ft_putstr_fd("\n", 0);
	ft_lst_print(alist);
	return (0);
}

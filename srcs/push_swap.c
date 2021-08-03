/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:10:59 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/03 16:28:15 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	parsing_str(char *str, t_list **alist)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(str, ' ');
	while (tmp[i] != NULL)
	{
		*alist = ft_lst_add_back(*alist, ft_atoi(tmp[i]));
		i++;
	}
	i = 0;
	while (tmp[i] != NULL)
		free(tmp[i++]);
	free(tmp);
}

void	parsing_base(t_list **alist, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 2)
			parsing_str(argv[i], alist);
		else
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
	ft_lst_print(alist);
	ft_lst_free(alist);
	return (0);
}

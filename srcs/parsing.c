/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:38:10 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/11 15:39:09 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	check_done(t_list *alist, t_list *blist)
{
	if (check_lst_sort(alist) == 1 && (!blist))
		ft_putstr_fd("list is in order\n", 0);
	else
		ft_putstr_fd("list isn't in order\n", 0);
}

int	check_lst_sort(t_list *list)
{
	t_list	*tmp;
	int		tmpval;

	tmp = list;
	while (tmp->next != NULL)
	{
		tmpval = tmp->value;
		tmp = tmp->next;
		if (tmpval > tmp->value)
			return (0);
	}
	return (1);
}

void	check_dup(t_list *alist)
{
	t_list	*tmplist;

	while (alist->next != NULL)
	{
		tmplist = alist->next;
		while (tmplist != NULL)
		{
			if (tmplist->value == alist->value)
				ft_exit_code("Error\nDuplicates in the list\n", 1);
			tmplist = tmplist->next;
		}
		alist = alist->next;
	}
}

void	parsing_str(char *str, t_list **alist)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(str, ' ');
	while (tmp[i] != NULL)
	{
		if (ft_is_digit_char(tmp[i]) == 0)
			ft_exit_code("Error\nNot a number\n", 1);
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
		{
			if (ft_is_digit_char(argv[i]) == 0)
				ft_exit_code("Error\nNot a number\n", 1);
			*alist = ft_lst_add_back(*alist, ft_atoi(argv[i]));
		}
		i++;
	}
}

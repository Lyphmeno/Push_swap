/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:36:58 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/17 17:29:56 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	t_list	*alist;
	t_list	*blist;
	int		min;
	int		max;
	int		mid;
}			t_data;

// Lib Basics
int		ft_atoi(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_exit_code(char	*str, int x);
int		ft_is_digit_char(char *str);
char	*ft_itoa(int n);
void	*ft_memset(void *b, int c, size_t len);
void	**ft_newarray(size_t w, size_t h, size_t size);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
char	**ft_split(const char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(char *str);
// Listes chainées
t_list	*ft_lst_add_back(t_list *list, int newelem);
void	ft_lst_add_front(t_list **list, int newelem);
void	ft_lst_pop_front(t_list **list);
void	ft_lst_pop_any(t_list **list, int key);
void	ft_lst_free(t_list *list);
int		ft_lst_getn(t_list *list, int index);
int		ft_lst_length(t_list *list);
void	ft_lst_print(t_list *list);
void	ft_lst_mid(t_list *list, t_data *data, int cmin, int cmax);
int		ft_lst_min(t_list *list);
int		ft_lst_max(t_list *list);
void	ft_lst_ex(t_list *list, t_data *data);
// Parsing
void	print_change(t_data *data);
void	check_done(t_data *data);
int		check_lst_sort(t_list *list);
void	check_dup(t_list *alist);
void	parsing_str(char *str, t_data *data);
void	parsing_base(t_data *data, int argc, char **argv);
// Operations
void	swap(t_list *list);
void	push(t_list *srclist, t_list *dstlist, char *str);
void	rotate(t_list **list, int x);
// Operations shortcut
void	sa(t_data *data);
void	sb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
// Sort
void	push_base(t_data *data);
void	push_swap_less(t_data *data);
#endif

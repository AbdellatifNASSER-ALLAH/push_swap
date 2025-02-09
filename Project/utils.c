/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:35:58 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/09 11:22:42 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->index != i++)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	get_index(int *arr, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (i);
		i++;
	}
	return (size);
}

void	fill_index_stack(t_list **a, int size)
{
	int		i;
	int		*arr;
	t_list	*tmp;

	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return ;
	i = 0;
	tmp = *a;
	while (tmp)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, size - 1);
	tmp = *a;
	while (tmp)
	{
		tmp->index = get_index(arr, tmp->content, size);
		tmp = tmp->next;
	}
	free(arr);
}

int	fill_stack(t_list **list, int ac, char **av)
{
	int		i;
	int		j;
	long	n;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			n = get_number(av[i], &j);
			if (j == -1 || ft_inlst(*list, n))
			{
				ft_lstclear(list);
				write(2, "Error\n", 6);
				return (0);
			}
			ft_lstadd_back(list, ft_lstnew(n));
		}
		i++;
	}
	if (!*list)
		return (write(2, "Error\n", 6), 0);
	fill_index_stack(list, ft_lstsize(*list));
	return (1);
}

long	get_number(char *str, int *j)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*j && !(str[*j] == 32) && !(str[*j] && str[*j] >= '0'
			&& str[*j] <= '9'))
		return (*j = -1);
	while (str[*j] == 32)
		(*j)++;
	if (str[*j] == '-' || str[*j] == '+')
	{
		if (str[*j] == '-')
			sign *= -1;
		(*j)++;
	}
	if (!(str[*j] && str[*j] >= '0' && str[*j] <= '9'))
		return (*j = -1);
	while (str[*j] && str[*j] >= '0' && str[*j] <= '9')
		res = res * 10 + (str[(*j)++] - 48);
	while (str[*j] == 32)
		(*j)++;
	return (res * sign);
}

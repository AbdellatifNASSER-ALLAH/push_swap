/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:35:58 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/08 14:16:30 by abdnasse         ###   ########.fr       */
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

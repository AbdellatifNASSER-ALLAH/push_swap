/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:17:29 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/05 17:00:36 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static	int	get_max(t_list *lst, int *b)
{
	int	max;

	max = lst->content;
	*b = 0;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	while (max >> *b)
		(*b)++;
	return (0);
}

static	void	radix_sort(t_list **a, t_list **b)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	bit = get_max(*a, &max_bits);
	size = ft_lstsize(*a);
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->content >> bit) & 1)
				rotate(a, b, RA);
			else
				push(a, b, PB);
			i++;
		}
		while(*b)
			push(a, b, PA);
		bit++;
	}
}*/

static	void	merge_stacks(t_list **a, t_list **b, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		if (*b && (!*a || (*a)->content > (*b)->content))
			push(a, b, PA);
		else
			rotate(a, b, RA);
		i++;
	}
}

static	void	merge_sort(t_list **a, t_list **b, int size)
{
	if (size <= 1)
		return ;
	int	halfsize;

	halfsize = size / 2;
	while (halfsize--)
		push(a, b, PB);
	halfsize = size / 2;
	merge_sort(a, b, size - halfsize);
	merge_sort(b, a, halfsize);
	merge_stacks(a, b, size);
}

void	sort_algo(t_list **a, t_list **b)
{
	//radix_sort(a, b);
	merge_sort(a, b, ft_lstsize(*a));	
}

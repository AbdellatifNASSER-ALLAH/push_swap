/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:44:57 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/06 22:27:48 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	increment(int *a, int *b)
{
	(*a)++;
	(*b)++;
}

void	push_to_b(t_list **a, t_list **b, int start, int end)
{
	while (*a)
	{
		if (*a && (*a)->index < start)
		{
			push(a, b, PB);
			rotate(a, b, RB);
			increment(&start, &end);
		}
		else if (*a && (*a)->index >= start && (*a)->index <= end)
		{
			push(a, b, PB);
			if (*b && (*b)->next && (*b)->index < (*b)->next->index)
				swap(a, b, SB);
			increment(&start, &end);
		}
		else
			rotate(a, b, RA);
	}
}

static int	in_first_half(t_list *lst, int *max, int size)
{
	t_list	*tmp;


	*max = 0;
	tmp = lst;
	while (lst)
	{
		if (lst->index > *max)
			*max = lst->index;
		lst = lst->next;
	}
	while (size--)
	{
		if (tmp->index == *max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	push_to_a(t_list **a, t_list **b, int max, int size)
{
	while(*b)
	{
		if (in_first_half(*b, &max, size / 2))
		{
			while (*b && (*b)->index != max)
				rotate(a, b, RB);
		}
		else 
		{
			while (*b && (*b)->index != max)
				rrotate(a, b, RRB);
		}
		if (*b)
		{
			push(a, b, PA);
			size--;
		}
	}
}

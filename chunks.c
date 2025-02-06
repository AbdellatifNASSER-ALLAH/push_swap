/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:44:57 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/06 19:27:43 by abdnasse         ###   ########.fr       */
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
		else if (*a && (*a)->index >= start (*a)->index <= end)
		{
			push(a, b, PB);
			if (*b && (*b)->index < (*b)->next->index)
				rotate(a, b, RB);
			increment(&start, &end);
		}
		else
			rotate(a, b, RA);
	}
}

void	push_to_a(t_list **a, t_list **b, int max, int size)
{
	while(*b)
	{
		
		size = ft_lstsize(*b);
	}
}

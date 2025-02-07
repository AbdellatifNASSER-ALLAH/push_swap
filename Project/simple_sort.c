/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:16:15 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/07 13:01:20 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_3(t_list **a, t_list **b, int min_index)
{
	while ((*a)->index != min_index)
		rotate(a, b, RA);
	if (is_sorted(*a))
		return ;
	push(a, b, PB);
	if ((*a)->index > (*a)->next->index)
		swap(a, b, SA);
	push(a, b, PA);
}

void	simple_sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			swap(a, b, SA);
	}
	else if (size == 3)
		sort_3(a, b, 0);
	else
	{
		while ((*a)->index != 0)
			rotate(a, b, RA);
		if (is_sorted(*a))
			return ;
		push(a, b, PB);
		sort_3(a, b, 1);
		push(a, b, PA);
	}
}

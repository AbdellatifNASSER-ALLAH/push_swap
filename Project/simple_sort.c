/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:16:15 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/10 10:07:11 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_list **a, t_list **b, int min_index)
{
	if ((*a)->index > (*a)->next->index
		&& (*a)->index < (*a)->next->next->index)
		swap(a, b, SA, 1);
	if ((*a)->index == min_index + 2 && (*a)->next->index == min_index + 1)
		swap(a, b, SA, 1);
	if ((*a)->next->next->index == min_index)
		rrotate(a, b, RRA, 1);
	else
		while ((*a)->index != min_index)
			rotate(a, b, RA, 1);
	if (is_sorted(*a))
		return ;
	push(a, b, PB, 1);
	if ((*a)->index > (*a)->next->index)
		swap(a, b, SA, 1);
	push(a, b, PA, 1);
}

static void	sort_4(t_list **a, t_list **b, int min_index)
{
	if ((*a)->index > (*a)->next->index)
		swap(a, b, SA, 1);
	if ((*a)->index == min_index || (*a)->next->index == min_index)
		while ((*a)->index != min_index)
			rotate(a, b, RA, 1);
	else
		while ((*a)->index != min_index)
			rrotate(a, b, RRA, 1);
	if (is_sorted(*a))
		return ;
	push(a, b, PB, 1);
	sort_3(a, b, min_index + 1);
	push(a, b, PA, 1);
}

void	simple_sort(t_list **a, t_list **b, int size)
{
	if ((*a)->index > (*a)->next->index && size == 2)
		swap(a, b, SA, 1);
	if (size == 3)
		sort_3(a, b, 0);
	else if (size == 4)
		sort_4(a, b, 0);
	else
	{
		if ((*a)->index == 0 || (*a)->next->index == 0
			|| (*a)->next->next->index == 0)
			while ((*a)->index != 0)
				rotate(a, b, RA, 1);
		else
			while ((*a)->index != 0)
				rrotate(a, b, RRA, 1);
		if (is_sorted(*a))
			return ;
		push(a, b, PB, 1);
		sort_4(a, b, 1);
		push(a, b, PA, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:33:14 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/02 17:34:51 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **a, t_list **b, t_op op)
{
	t_list *tmp;
	
	if ((op == SA || op == SS) && (*a && (*a)->next))
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
		if (op == SA)
			write(1, "sa\n", 3);
	}
	if ((op == SB || op == SS) && (*b && (*b)->next))
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
		if (op == SB)
			write(1, "sb\n", 3);
	}
	if (op == SS)
		write(1, "ss\n", 3);
}

void	push(t_list **a, t_list **b, t_op op)
{
	t_list	*tmp;

	if (*b && op == PA)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		write(1, "pa\n", 3);
	}
	if (*a && op == PB)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		write(1, "pb\n", 3);
	}
}
void	rotate(t_list **a, t_list **b, t_op op);
void	rrotate(t_list **a, t_list **b, t_op op);

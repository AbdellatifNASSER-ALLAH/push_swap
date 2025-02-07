/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:33:14 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/06 21:00:58 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_last(t_list *lst, int before_last)
{
	if (before_last)
	{
		while (lst->next->next)
			lst = lst->next;
	}
	else
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	swap(t_list **a, t_list **b, t_op op)
{
	t_list	*tmp;

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

void	rotate(t_list **a, t_list **b, t_op op)
{
	t_list	*last;
	t_list	*tmp;

	if ((op == RA || op == RR) && (*a && (*a)->next))
	{
		last = get_last(*a, 0);
		tmp = *a;
		*a = tmp->next;
		last->next = tmp;
		tmp->next = NULL;
		if (op == RA)
			write(1, "ra\n", 3);
	}
	if ((op == RB || op == RR) && (*b && (*b)->next))
	{
		last = get_last(*b, 0);
		tmp = *b;
		*b = tmp->next;
		last->next = tmp;
		tmp->next = NULL;
		if (op == RB)
			write(1, "rb\n", 3);
	}
	if (op == RR)
		write(1, "rr\n", 3);
}

void	rrotate(t_list **a, t_list **b, t_op op)
{
	t_list	*blast;
	t_list	*tmp;

	if ((op == RRA || op == RRR) && (*a && (*a)->next))
	{
		tmp = get_last(*a, 0);
		blast = get_last(*a, 1);
		tmp->next = *a;
		*a = tmp;
		blast->next = NULL;
		if (op == RRA)
			write(1, "rra\n", 4);
	}
	if ((op == RRB || op == RRR) && (*b && (*b)->next))
	{
		tmp = get_last(*b, 0);
		blast = get_last(*b, 1);
		tmp->next = *b;
		*b = tmp;
		blast->next = NULL;
		if (op == RRB)
			write(1, "rrb\n", 4);
	}
	if (op == RRR)
		write(1, "rrr\n", 4);
}

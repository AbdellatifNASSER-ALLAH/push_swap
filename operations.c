/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:33:14 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/01 23:49:54 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **a, t_list **b, int o)
{
	t_list *tmp;

	if (o == SA || o == SS)
	{
		tmp = *a->next;
		*a->next = tmp->next;
		*a = tmp;
		if (o == SA)
			write(1, "sa\n", 3);
	}
	if (o == SB || o == SS)
	{
		tmp = *b->next;
		*b->next = tmp->next;
		*b = tmp;
		if (o == SB)
			write(1, "sb\n", 3);
	}
	if (o == SS)
		write(1, "ss\n", 3);
}
void	push(t_list **a, t_list **b, int o);
void	rotate(t_list **a, t_list **b, int o);
void	rrotate(t_list **a, t_list **b, int o);

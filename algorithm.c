/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:17:29 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/04 16:32:48 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_max(t_list *lst, int *b)
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

void	sort_algo(t_list **a, t_list **b)
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
}

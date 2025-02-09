/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:17:29 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/09 11:21:40 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algo(t_list **a, t_list **b, int size)
{
	int	end;

	if (is_sorted(*a))
		return ;
	if (size < 6)
		return (simple_sort(a, b, size));
	if (size <= 100)
		end = size / 6;
	else
		end = size / 14;
	push_to_b(a, b, 0, end);
	push_to_a(a, b, size - 1, size);
}

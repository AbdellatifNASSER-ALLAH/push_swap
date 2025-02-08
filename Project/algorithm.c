/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:17:29 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/08 22:00:20 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(int *arr, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (i);
		i++;
	}
	return (size);
}

static void	fill_index_stack(t_list **a, int size)
{
	int		i;
	int		*arr;
	t_list	*tmp;

	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return ;
	i = 0;
	tmp = *a;
	while (tmp)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, size - 1);
	tmp = *a;
	while (tmp)
	{
		tmp->index = get_index(arr, tmp->content, size);
		tmp = tmp->next;
	}
	free(arr);
}

void	sort_algo(t_list **a, t_list **b, int size)
{
	int	end;

	fill_index_stack(a, size);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:42:04 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/06 17:41:21 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

static	int	partition(int *arr, int low, int high)
{
	int	i;
	int	j;

	i = low;
	j = high;
	while (i < j)
	{
		while (arr[i] <= arr[low] && i < high)
			i++;
		while(arr[j] > arr[low] && j > low)
			j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	if (j <= i)
		swap(&arr[low], &arr[j]);
	return (j);
}

void	quick_sort(int	*arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:39 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/03 10:16:31 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	view_list(t_list *a, t_list *b)
{
	int	size;

	size = ft_lstsize(a) > ft_lstsize(b) ? ft_lstsize(a) : ft_lstsize(b);
	printf("_______________________\n");
	while (size)
	{
		a ? printf("|  %d  ", a->content) : printf("|  -  ");
		b ? printf("|  %d  |\n", b->content) : printf("|  -  |\n");
		a = a ? a->next : NULL;
		b = b ? b->next : NULL;
		size--;
	}
	printf("   _     _\n   a     b  \n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac != 1)
	{
		a = NULL;
		b = NULL;
		if (!fill_stack(&a, ac, av))
			return (1);
		// TODO: the algorithm to sort the stack a
		push(&a, &b, PB);
		view_list(a, b);
		push(&a, &b, PB);
		view_list(a, b);
		push(&a, &b, PB);
		view_list(a, b);
		rotate(&a, &b, RA);
		view_list(a, b);
		rotate(&a, &b, RB);
		view_list(a, b);
		rotate(&a, &b, RR);
		view_list(a, b);
	}
	return (0);
}

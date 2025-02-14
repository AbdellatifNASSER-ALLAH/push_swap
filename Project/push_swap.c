/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:39 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/10 10:40:34 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac != 1)
	{
		a = NULL;
		b = NULL;
		if (!is_valid(av, ac) || !fill_stack(&a, ac, av))
			return (1);
		sort_algo(&a, &b, ft_lstsize(a));
		ft_lstclear(&a);
	}
	return (0);
}

int	is_valid(char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!av[i][0])
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

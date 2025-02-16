/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:39 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/16 18:40:22 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_input(char *move)
{
	size_t	bits;
	int		i;

	i = 0;
	while (1)
	{
		bits = read(0, move + i, 1);
		if (bits <= 0)
			return (0);
		if (move[i++] == '\n')
			break ;
	}
	move[i] = 0;
	return (1);
}

static int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

static int	do_move(t_list **a, t_list **b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		swap(a, b, SA, 0);
	else if (!ft_strcmp(move, "sb\n"))
		swap(a, b, SB, 0);
	else if (!ft_strcmp(move, "sa\n"))
		swap(a, b, SS, 0);
	else if (!ft_strcmp(move, "pa\n"))
		push(a, b, PA, 0);
	else if (!ft_strcmp(move, "pb\n"))
		push(a, b, PB, 0);
	else if (!ft_strcmp(move, "ra\n"))
		rotate(a, b, RA, 0);
	else if (!ft_strcmp(move, "rb\n"))
		rotate(a, b, RB, 0);
	else if (!ft_strcmp(move, "rr\n"))
		rotate(a, b, RR, 0);
	else if (!ft_strcmp(move, "rra\n"))
		rrotate(a, b, RRA, 0);
	else if (!ft_strcmp(move, "rrb\n"))
		rrotate(a, b, RRB, 0);
	else if (!ft_strcmp(move, "rrr\n"))
		rrotate(a, b, RRR, 0);
	else
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	move[4];

	if (ac != 1)
	{
		a = NULL;
		b = NULL;
		if (!is_valid(av, ac) || !fill_stack(&a, ac, av))
			return (1);
		while (1)
		{
			if (!read_input(move))
				break ;
			if (!do_move(&a, &b, move))
				return (ft_lstclear(&a), ft_lstclear(&b), 1);
		}
		if (is_sorted(a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_lstclear(&a);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:39 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/09 12:25:19 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	view_list(t_list *a, t_list *b);

static	int	read_input(char *move)
{
	size_t	bits;
	int	i;

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

static	int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

static	void	do_move(t_list **a, t_list **b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		swap(a , b, SA);
	else if (!ft_strcmp(move, "sb\n"))
		swap(a , b, SB);
	else if (!ft_strcmp(move, "sa\n"))
		swap(a , b, SS);
	else if (!ft_strcmp(move, "pa\n"))
		push(a, b, PA);
	else if (!ft_strcmp(move, "pb\n"))
		push(a, b, PB);
	else if (!ft_strcmp(move, "ra\n"))
		rotate(a, b, RA);
	else if (!ft_strcmp(move, "rb\n"))
		rotate(a, b, RB);
	else if (!ft_strcmp(move, "rr\n"))
		rotate(a, b, RR);
	else if (!ft_strcmp(move, "rra\n"))
		rrotate(a, b, RRA);
	else if (!ft_strcmp(move, "rrb\n"))
		rrotate(a, b, RRB);
	else if (!ft_strcmp(move, "rrr\n"))
		rrotate(a, b, RRR);
	else 
		write(2, "Error\n", 6);
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
		if (!fill_stack(&a, ac, av))
			return (1);
		while(1)
		{
			if (!read_input(move))
				break ;
			do_move(&a, &b, move);
		}
		if (is_sorted(a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		view_list(a, b);
		ft_lstclear(&a);
	}
	return (0);
}

// JUST FOR SHOWING LISTS
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

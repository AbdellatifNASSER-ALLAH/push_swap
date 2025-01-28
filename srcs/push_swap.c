/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:39 by abdnasse          #+#    #+#             */
/*   Updated: 2025/01/28 16:02:00 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill stack(t_list **list, int ac, char **av);
int	check_error(char *str);

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac != 1)
	{
		//Fill the stack a
		a = NULL;
		b = NULL;
		if (!fill_stack(&a, ac, av))
			return (1);

	//TODO: the algorithm to sort the stack a 
	}
}

int	fill stack(t_list **list, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while( i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			if (check_error(av[i]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			//TODO: error if the number is dublicated
			j++;
		}
		i++;
	}
}


int	check_error(char *str)
{
	while (*str)
	{
		//TODO: error if the number is not intergers
		if(*str

		//TODO: error if the number is bigger that the limits of the Ingteger
		str++;
	}

}

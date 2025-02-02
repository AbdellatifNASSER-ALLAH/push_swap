/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:08:22 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/02 17:33:14 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
//TODO: I guess it obvious :)
#include <stdio.h>

typedef	struct	 s_list{
	int	content;
	struct	s_list	*next;
}	t_list;
//Utils: 
int	ft_inlst(t_list *lst, long n);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst);
void				ft_lstclear(t_list **lst);
int	fill_stack(t_list **list, int ac, char **av);
long	get_number(char *str, int *j);
//Operations:
typedef enum e_op
{
    SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
} t_op;

void	swap(t_list **a, t_list **b, t_op op);
void	push(t_list **a, t_list **b, t_op op);
void	rotate(t_list **a, t_list **b, t_op op);
void	rrotate(t_list **a, t_list **b, t_op op);

#endif

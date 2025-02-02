/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:08:22 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/02 13:22:22 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define SA 1
#define SB 2
#define SS 3
#define PA 4 
#define PB 5
#define RA 6
#define RB 7
#define RR 8
#define RRA 9
#define RRB 10
#define RRR 11

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
void	swap(t_list **a, t_list **b, int o);
void	push(t_list **a, t_list **b, int o);
void	rotate(t_list **a, t_list **b, int o);
void	rrotate(t_list **a, t_list **b, int o);

#endif

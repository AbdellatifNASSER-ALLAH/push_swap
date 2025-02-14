/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:08:22 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/10 10:12:26 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;
// Sort algorithm
void				sort_algo(t_list **a, t_list **b, int size);
void				quick_sort(int *arr, int low, int high);
void				push_to_a(t_list **a, t_list **b, int start, int end);
void				push_to_b(t_list **a, t_list **b, int max, int size);
void				simple_sort(t_list **a, t_list **b, int size);
// Utils:
int					is_sorted(t_list *lst);
int					ft_inlst(t_list *lst, long n);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst);
void				ft_lstclear(t_list **lst);
int					fill_stack(t_list **list, int ac, char **av);
void				fill_index_stack(t_list **a, int size);
long				get_number(char *str, int *j);
int					is_valid(char **av, int ac);
// Operations:
typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_op;

void				swap(t_list **a, t_list **b, t_op op, int yes);
void				push(t_list **a, t_list **b, t_op op, int yes);
void				rotate(t_list **a, t_list **b, t_op op, int yes);
void				rrotate(t_list **a, t_list **b, t_op op, int yes);

#endif

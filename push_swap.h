/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:08:22 by abdnasse          #+#    #+#             */
/*   Updated: 2025/02/01 23:00:18 by abdnasse         ###   ########.fr       */
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
int	ft_inlst(t_list *lst, int n);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst);
void				ft_lstclear(t_list **lst);

int	fill_stack(t_list **list, int ac, char **av);
int	get_number(char *str, int *j);

#endif

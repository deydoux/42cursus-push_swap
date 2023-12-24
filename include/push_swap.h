/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:23:10 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/24 15:17:04 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdbool.h>

typedef struct s_elem
{
	int		value;
	size_t	index;
}			t_elem;

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}			t_stacks;

void	free_stacks(t_stacks stacks);
void	index_stack(t_list *stack);
bool	init_stacks(int argc, char **argv, t_stacks *stacks);
bool	parse_args(int argc, char **argv, t_list **stack);

bool	pa(t_stacks stacks);
bool	pb(t_stacks stacks);
bool	ra(t_stacks stacks);
bool	rb(t_stacks stacks);
bool	rr(t_stacks stacks);
bool	sa(t_stacks stacks);
bool	sb(t_stacks stacks);
bool	ss(t_stacks stacks);

#endif

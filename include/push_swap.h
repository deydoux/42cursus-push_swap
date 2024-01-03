/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:23:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 02:12:15 by deydoux          ###   ########.fr       */
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

typedef void	(*t_operation)(t_stacks);

void	free_stacks(t_stacks stacks);
void	index_stack(t_list *stack);
bool	init_stacks(int argc, char **argv, t_stacks *stacks);
bool	is_sorted_stack(t_list *stack);
bool	parse_args(int argc, char **argv, t_list **stack);
void	sort_five(t_stacks stacks);
void	sort_three(t_stacks stacks);

void	pa(t_stacks stacks);
void	pb(t_stacks stacks);
void	ra(t_stacks stacks);
void	rb(t_stacks stacks);
void	rr(t_stacks stacks);
void	rra(t_stacks stacks);
void	rrb(t_stacks stacks);
void	rrr(t_stacks stacks);
void	sa(t_stacks stacks);
void	sb(t_stacks stacks);
void	ss(t_stacks stacks);

#endif

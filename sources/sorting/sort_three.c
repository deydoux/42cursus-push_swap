/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:46:04 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/30 14:51:05 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Match 1, 0 index sequence (next of end is start)
static bool	sa_sequence(t_list *stack)
{
	t_list	*start;
	t_list	*next;

	start = stack;
	while (stack)
	{
		next = stack->next;
		if (!next)
			next = start;
		if (((t_elem *)stack->content)->index == 1
			&& ((t_elem *)next->content)->index == 0)
			return (true);
		stack = stack->next;
	}
	return (false);
}

// Match 2, 0, 1 index sequence
static bool	ra_sequence(t_list *stack)
{
	return (((t_elem *)stack->content)->index == 2
		&& ((t_elem *)stack->next->content)->index == 0);
}

// Match 1, 2, 0 index sequence
static bool	rra_sequence(t_list *stack)
{
	return (((t_elem *)stack->content)->index == 1
		&& ((t_elem *)stack->next->content)->index == 2);
}

void	sort_three(t_stacks stacks)
{
	if (sa_sequence(*stacks.a))
		sa(stacks);
	if (ra_sequence(*stacks.a))
		ra(stacks);
	else if (rra_sequence(*stacks.a))
		rra(stacks);
}

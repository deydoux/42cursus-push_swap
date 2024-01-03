/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:46:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 03:25:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Match 1, 0 index sequence (next of end is start)
static void	swap_sequence(t_stacks stacks, bool *unsort_b)
{
	t_list	*stack;
	t_list	*start;
	t_list	*next;

	stack = *stacks.a;
	start = stack;
	while (stack)
	{
		next = stack->next;
		if (!next)
			next = start;
		if (((t_elem *)stack->content)->index == 1
			&& ((t_elem *)next->content)->index == 0)
		{
			if (*unsort_b)
				ss(stacks);
			else
				sa(stacks);
			*unsort_b = false;
			return ;
		}
		stack = stack->next;
	}
}

// Match 2, 0, 1 index sequence
static bool	rotate_sequence(t_stacks stacks, bool unsort_b)
{
	if (((t_elem *)(*stacks.a)->content)->index == 2
		&& ((t_elem *)(*stacks.a)->next->content)->index == 0)
	{
		if (unsort_b)
			rr(stacks);
		else
			ra(stacks);
		return (true);
	}
	return (false);
}

// Match 1, 2, 0 index sequence
static void	reverse_rotate_sequence(t_stacks stacks, bool unsort_b)
{
	if (((t_elem *)(*stacks.a)->content)->index == 1
		&& ((t_elem *)(*stacks.a)->next->content)->index == 2)
	{
		if (unsort_b)
			rrr(stacks);
		else
			rra(stacks);
	}
}

void	sort_three(t_stacks stacks)
{
	bool		unsort_b;

	unsort_b = *stacks.b && (*stacks.b)->next
		&& ((t_elem *)(*stacks.b)->content)->index
		< ((t_elem *)(*stacks.b)->next->content)->index;
	index_stack(*stacks.a);
	swap_sequence(stacks, &unsort_b);
	if (!rotate_sequence(stacks, unsort_b))
		reverse_rotate_sequence(stacks, unsort_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:46:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 18:13:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Match 1, 0 index sequence (next of end is start)
static void	swap_sequence(t_stacks stacks, bool *b_sorted)
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
			if (*b_sorted)
				swap_a(stacks);
			else
				swap_stacks(stacks);
			*b_sorted = true;
			return ;
		}
		stack = stack->next;
	}
}

// Match 2, 0, 1 index sequence
static bool	rotate_sequence(t_stacks stacks, bool *b_sorted)
{
	if (((t_elem *)(*stacks.a)->content)->index == 2
		&& ((t_elem *)(*stacks.a)->next->content)->index == 0)
	{
		if (*b_sorted)
			rotate_a(stacks);
		else
			rotate_stacks(stacks);
		*b_sorted = true;
		return (true);
	}
	return (false);
}

// Match 1, 2, 0 index sequence
static void	reverse_rotate_sequence(t_stacks stacks, bool *b_sorted)
{
	if (((t_elem *)(*stacks.a)->content)->index == 1
		&& ((t_elem *)(*stacks.a)->next->content)->index == 2)
	{
		if (*b_sorted)
			reverse_rotate_a(stacks);
		else
			reverse_rotate_stacks(stacks);
		*b_sorted = true;
	}
}

void	sort_three(t_stacks stacks, bool *b_sorted)
{
	index_stack(*stacks.a);
	swap_sequence(stacks, b_sorted);
	if (!rotate_sequence(stacks, b_sorted))
		reverse_rotate_sequence(stacks, b_sorted);
}

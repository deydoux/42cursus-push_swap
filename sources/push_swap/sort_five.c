/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:27:44 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/11 14:38:05 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_operation	get_rotation(t_list *stack, bool pushed)
{
	size_t	rotations;
	size_t	reverse_rotations;

	rotations = 0;
	reverse_rotations = 0;
	while (((t_elem *)stack->content)->index > 1)
	{
		rotations++;
		stack = stack->next;
	}
	if (!pushed)
		while (((t_elem *)stack->next->content)->index > 1)
			stack = stack->next;
	while (stack->next)
	{
		reverse_rotations++;
		stack = stack->next;
	}
	if (reverse_rotations < rotations)
		return (reverse_rotate_a);
	return (rotate_a);
}

void	sort_five(t_stacks stacks)
{
	t_operation	rotation;
	bool		b_sorted;

	rotation = get_rotation(*stacks.a, false);
	while (((t_elem *)(*stacks.a)->content)->index > 1)
		rotation(stacks);
	push_b(stacks);
	rotation = get_rotation(*stacks.a, true);
	while (((t_elem *)(*stacks.a)->content)->index > 1)
		rotation(stacks);
	push_b(stacks);
	b_sorted = is_sorted_stack(*stacks.b);
	index_stack(*stacks.a, 3);
	sort_three(stacks, &b_sorted);
	if (!b_sorted)
		swap_b(stacks);
	push_a(stacks);
	push_a(stacks);
}

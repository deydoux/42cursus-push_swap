/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:27:44 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 03:14:51 by deydoux          ###   ########.fr       */
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
		return (rra);
	return (ra);
}

void	sort_five(t_stacks stacks)
{
	t_operation	rotation;

	index_stack(*stacks.a);
	rotation = get_rotation(*stacks.a, false);
	while (((t_elem *)(*stacks.a)->content)->index > 1)
		rotation(stacks);
	pb(stacks);
	rotation = get_rotation(*stacks.a, true);
	while (((t_elem *)(*stacks.a)->content)->index > 1)
		rotation(stacks);
	pb(stacks);
	sort_three(stacks);
	if (((t_elem *)(*stacks.b)->content)->index
		< ((t_elem *)(*stacks.b)->next->content)->index)
		sb(stacks);
	pa(stacks);
	pa(stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:34:46 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/25 16:10:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	in_chunk(t_list *stack, size_t min, size_t max)
{
	size_t	index;

	index = ((t_elem *)stack->content)->index;
	return (min <= index && index < max);
}

static t_operation	get_rotation(t_list *stack, size_t min, size_t max)
{
	size_t	rotations;
	size_t	reverse_rotations;

	rotations = 0;
	while (stack && !in_chunk(stack, min, max))
	{
		rotations++;
		stack = stack->next;
	}
	if (!stack)
		return (NULL);
	if (!rotations)
		return (rotate_a);
	while (stack)
	{
		if (in_chunk(stack, min, max))
			reverse_rotations = 0;
		reverse_rotations++;
		stack = stack->next;
	}
	if (reverse_rotations < rotations)
		return (reverse_rotate_a);
	return (rotate_a);
}

void	chunk_stack(size_t chunks, size_t size, t_stacks stacks)
{
	size_t		current;
	size_t		min;
	size_t		max;
	t_operation	rotation;

	current = 0;
	while (current < chunks)
	{
		min = current * size;
		max = ++current * size;
		rotation = get_rotation(*stacks.a, min, max);
		while (*stacks.a && (*stacks.a)->next && (*stacks.a)->next->next
			&& rotation)
		{
			while (!in_chunk(*stacks.a, min, max))
				rotation(stacks);
			push_b(stacks);
			rotation = get_rotation(*stacks.a, min, max);
		}
	}
}

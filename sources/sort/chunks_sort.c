/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:20:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/04 20:01:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	in_range(t_list *stack, size_t min, size_t max)
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
	while (stack && !in_range(stack, min, max))
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
		if (in_range(stack, min, max))
			reverse_rotations = 0;
		reverse_rotations++;
		stack = stack->next;
	}
	if (reverse_rotations < rotations)
		return (reverse_rotate_a);
	return (rotate_a);
}

static void	push_chunk(t_stacks stacks, size_t min, size_t max)
{
	t_operation	rotation;

	rotation = get_rotation(*stacks.a, min, max);
	while (rotation)
	{
		while (!in_range(*stacks.a, min, max))
			rotation(stacks);
		push_b(stacks);
		rotation = get_rotation(*stacks.a, min, max);
	}
}

static t_operation	get_chunk_rotation(t_list *stack, size_t index)
{
	size_t	rotations;
	size_t	reverse_rotations;

	rotations = 0;
	while (((t_elem *)stack->content)->index != index)
	{
		rotations++;
		stack = stack->next;
	}
	while (stack)
	{
		if (((t_elem *)stack->content)->index == index)
			reverse_rotations = 0;
		reverse_rotations++;
		stack = stack->next;
	}
	if (reverse_rotations < rotations)
		return (reverse_rotate_b);
	return (rotate_b);
}

void	chunks_sort(t_stacks stacks)
{
	size_t		size;
	size_t		chunks;
	size_t		chunk_size;
	size_t		current;
	t_operation	rotation;

	size = ft_lstsize(*stacks.a);
	chunks = size / MIN_CHUNK_SIZE;
	if (chunks > MAX_CHUNKS)
		chunks = MAX_CHUNKS;
	chunk_size = size / chunks + (size % chunks != 0);
	index_stack(*stacks.a);
	current = 0;
	while (current < chunks)
	{
		push_chunk(stacks, current * chunk_size, (current + 1) * chunk_size);
		current++;
	}
	while (size--)
	{
		rotation = get_chunk_rotation(*stacks.b, size);
		while (((t_elem *)(*stacks.b)->content)->index != size)
			rotation(stacks);
		push_a(stacks);
	}
}

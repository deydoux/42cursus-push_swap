/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:34:46 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/15 08:00:37 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	in_chunk(t_list *stack, size_t min, size_t max)
{
	size_t	index;

	index = ((t_elem *)stack->content)->index;
	return (min <= index && index < max);
}

static int	get_direction(t_list *stack, size_t min, size_t max,
	size_t rotations[2])
{
	rotations[0] = 0;
	while (stack && !in_chunk(stack, min, max))
	{
		rotations[0]++;
		stack = stack->next;
	}
	if (!stack)
		return (0);
	if (!rotations[0])
		return (1);
	while (stack)
	{
		if (in_chunk(stack, min, max))
			rotations[1] = 0;
		rotations[1]++;
		stack = stack->next;
	}
	if (rotations[1] < rotations[0])
	{
		rotations[0] = rotations[0];
		return (-1);
	}
	return (1);
}

static t_operation	get_rotation(size_t n, int direction, t_stacks stacks)
{
	t_list	*stack;

	if (direction == 1)
		stack = simulate_rotations(n, *stacks.b);
	else
		stack = simulate_reverse_rotations(n, *stacks.b);

}

static bool	add_to_chunk(t_stacks stacks, size_t min, size_t max)
{
	int		direction;
	size_t	rotations[2];

	direction = get_direction(*stacks.a, min, max, rotations);
	if (!direction)
		return (true);
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
		while (rotation)
		{
			while (!in_chunk(*stacks.a, min, max))
				rotation(stacks);
			push_b(stacks);
			rotation = get_rotation(*stacks.a, min, max);
		}
	}
}

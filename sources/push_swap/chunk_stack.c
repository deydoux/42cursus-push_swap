/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:34:46 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/15 18:24:04 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	in_chunk(t_list *stack, size_t min, size_t max)
{
	size_t	index;

	index = ((t_elem *)stack->content)->index;
	return (min <= index && index < max);
}

static int	get_direction(t_list *stack, size_t min, size_t max, size_t n[2])
{
	n[0] = 0;
	while (stack && !in_chunk(stack, min, max))
	{
		n[0]++;
		stack = stack->next;
	}
	if (!stack)
		return (0);
	if (!n[0])
		return (1);
	while (stack)
	{
		if (in_chunk(stack, min, max))
			n[1] = 0;
		n[1]++;
		stack = stack->next;
	}
	if (n[1] < n[0])
	{
		n[0] = n[1];
		return (-1);
	}
	return (1);
}

static t_operation	get_rotation(size_t n, int direction, t_stacks stacks)
{
	t_list	*target;
	t_list	*stack;

	if (direction == 1)
	{
		target = simulate_rotations(n, *stacks.a);
		stack = simulate_rotations(n, *stacks.b);
		if (stack && ((t_elem *)target->content)->index
			< ((t_elem *)stack->content)->index)
			return (rotate_stacks);
		return (rotate_a);
	}
	target = simulate_reverse_rotations(n, *stacks.a);
	stack = simulate_reverse_rotations(n, *stacks.b);
	if (stack && ((t_elem *)target->content)->index
		< ((t_elem *)stack->content)->index)
		return (reverse_rotate_stacks);
	return (reverse_rotate_a);
}

static bool	push_chunk(t_stacks stacks, size_t min, size_t max)
{
	int		direction;
	size_t	rotations[2];

	direction = get_direction(*stacks.a, min, max, rotations);
	if (!direction)
		return (true);
	while (!in_chunk(*stacks.a, min, max))
		get_rotation(rotations[0], direction, stacks)(stacks);
	push_b(stacks);
	return (false);
}

void	chunk_stack(size_t chunks, size_t size, t_stacks stacks)
{
	size_t	current;
	size_t	min;
	size_t	max;

	current = 0;
	while (current < chunks)
	{
		min = current * size;
		max = ++current * size;
		while (!push_chunk(stacks, min, max))
			continue ;
	}
}

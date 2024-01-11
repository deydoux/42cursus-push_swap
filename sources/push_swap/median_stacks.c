/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:29:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/11 15:36:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	above_median(t_list *stack, size_t median)
{
	return (((t_elem *)stack->content)->index > median);
}

static t_operation	get_rotation(t_list *stack, size_t median)
{
	size_t	rotations;
	size_t	reverse_rotations;

	rotations = 0;
	while (stack && !above_median(stack, median))
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
		if (above_median(stack, median))
			reverse_rotations = 0;
		reverse_rotations++;
		stack = stack->next;
	}
	if (reverse_rotations < rotations)
		return (reverse_rotate_a);
	return (rotate_a);
}

void	median_stacks(t_stacks stacks, size_t size)
{
	size_t		median;
	t_operation	rotation;

	median = size / 2;
	rotation = get_rotation(*stacks.a, median);
	while (rotation)
	{
		while (!above_median(*stacks.a, median))
			rotation(stacks);
		push_b(stacks);
		rotation = get_rotation(*stacks.a, median);
	}
}

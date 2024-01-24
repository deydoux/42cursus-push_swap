/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:20:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/25 11:48:27 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_operation	get_rotation(t_list *stack, size_t index)
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

void	chunks_sort(t_stacks stacks, size_t size)
{
	t_operation	rotation;

	chunk_stack(CHUNKS, size / CHUNKS, stacks);
	while (size-- && false)
	{
		rotation = get_rotation(*stacks.b, size);
		while (((t_elem *)(*stacks.b)->content)->index != size)
			rotation(stacks);
		push_a(stacks);
	}
}

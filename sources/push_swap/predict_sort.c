/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predict_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:20:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/25 16:42:25 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_b_rotations(t_moves *moves, t_stacks stacks)
{
	t_operation	rotation;

	if (moves->rra == moves->rrb)
	{
		if (moves->rra)
			rotation = reverse_rotate_stacks;
		else
			rotation = rotate_stacks;
		while (moves->ra && moves->rb)
		{
			rotation(stacks);
			moves->ra--;
			moves->rb--;
		}
	}
	if (moves->rrb)
		rotation = reverse_rotate_b;
	else
		rotation = rotate_b;
	while (moves->rb--)
		rotation(stacks);
}

void	predict_sort(t_stacks stacks, size_t size)
{
	t_moves		moves;
	t_operation	rotation;

	chunk_stack(size-- / 3, stacks);
	while (size--)
	{
		moves = compute_moves(*stacks.b, 0, size / 2 + (size % 2), stacks);
		do_b_rotations(&moves, stacks);
		if (moves.rra)
			rotation = reverse_rotate_a;
		else
			rotation = rotate_a;
		while (moves.ra)
			rotation(stacks);
		push_a(stacks);
	}
}

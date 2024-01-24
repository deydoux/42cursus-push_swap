/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:49:16 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/25 13:53:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_moves(int index, t_list *stack, t_moves *moves)
{

}

static void	b_moves(size_t position, size_t middle, t_moves *moves)
{
	if (position < middle)
	{
		moves->rb = position;
		moves->rrb = false;
	}
	else
	{
		moves->rb = position - middle;
		moves->rrb = true;
	}
}

static size_t	sum_moves(t_moves moves)
{
	if (moves.rra != moves.rrb)
		return (moves.ra + moves.rb);
	if (moves.ra > moves.rb)
		return (moves.ra);
	return (moves.rb);
}

t_moves	compute_moves(t_list *stack, size_t pos, size_t middle, t_stacks stacks)
{
	t_moves	moves;
	t_moves	next_moves;

	a_moves(((t_elem *)stack->content)->index, *stacks.a, &moves);
	b_moves(pos, middle, &moves);
	moves.sum = sum_moves(moves);
	if (!stack->next)
		return (moves);
	next_moves = compute_moves(stack->next, pos + 1, middle, stacks);
	if (moves.sum < next_moves.sum)
		return (moves);
	return (next_moves);
}

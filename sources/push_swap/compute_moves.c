/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:49:16 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/25 16:28:25 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compute_a_moves(int value, t_list *stack, t_moves *moves)
{
	t_elem	*elem;
	size_t	reverse;

	elem = greater_elem(value, stack);
	moves->ra = 0;
	moves->rra = false;
	if (!elem)
		return ;
	while (stack->content != elem)
	{
		moves->ra++;
		stack = stack->next;
	}
	reverse = 0;
	while (stack)
	{
		reverse++;
		stack = stack->next;
	}
	if (reverse < moves->ra || (reverse == moves->ra && moves->rrb))
	{
		moves->ra = reverse;
		moves->rra = true;
	}
}

static void	compute_b_moves(size_t position, size_t middle, t_moves *moves)
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

t_moves	compute_moves(t_list *b, size_t position, size_t half, t_stacks stacks)
{
	t_moves	moves;
	t_moves	next_moves;

	compute_a_moves(((t_elem *)b->content)->value, *stacks.a, &moves);
	compute_b_moves(position, half, &moves);
	moves.sum = sum_moves(moves);
	if (!b->next)
		return (moves);
	next_moves = compute_moves(b->next, position + 1, half, stacks);
	if (moves.sum > next_moves.sum)
		return (next_moves);
	return (moves);
}

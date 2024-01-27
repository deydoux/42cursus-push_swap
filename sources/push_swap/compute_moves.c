/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:49:16 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/27 14:51:19 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compute_b_moves(t_list *stack, size_t position, t_moves *moves)
{
	size_t	reverse;

	reverse = 0;
	while (stack)
	{
		reverse++;
		stack = stack->next;
	}
	if (position < reverse)
	{
		moves->rb = position;
		moves->rrb = false;
	}
	else
	{
		moves->rb = reverse;
		moves->rrb = true;
	}
}

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

static size_t	sum_moves(t_moves moves)
{
	if (moves.rra != moves.rrb)
		return (moves.ra + moves.rb);
	if (moves.ra > moves.rb)
		return (moves.ra);
	return (moves.rb);
}

t_moves	compute_moves(t_list *stack, t_stacks stacks, size_t position)
{
	t_moves	moves;
	t_moves	next_moves;

	compute_b_moves(stack, position, &moves);
	compute_a_moves(((t_elem *)stack->content)->value, *stacks.a, &moves);
	moves.sum = sum_moves(moves);
	if (!stack->next)
		return (moves);
	next_moves = compute_moves(stack->next, stacks, position + 1);
	if (moves.sum > next_moves.sum)
		return (next_moves);
	return (moves);
}

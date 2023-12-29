/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:46:04 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/29 19:09:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Match 3, 2 sequence, next of end is start
static bool	sa_sequence(t_list *stack)
{
	t_list	*start;
	t_list	*next;

	start = stack;
	while (stack)
	{
		next = stack->next;
		if (!next)
			next = start;
		if (((t_elem *)stack->content)->index == 2
			&& ((t_elem *)next->content)->index == 1)
			return (true);
		stack = stack->next;
	}
	return (false);
}

// Match 3, 1 sequence
static bool	ra_sequence(t_list *stack)
{
	while (stack->next)
	{
		if (((t_elem *)stack->content)->index == 2
			&& ((t_elem *)stack->next->content)->index == 0)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	sort_three(t_stacks stacks)
{
	if (sa_sequence(*stacks.a))
		sa(stacks);
	if (ra_sequence(*stacks.a))
	{
		if (((t_elem *)(*stacks.a)->content)->index == 2)
			ra(stacks);
		else
			rra(stacks);
	}
}

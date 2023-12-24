/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:19:04 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/24 15:23:12 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	reverse_rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return (true);
	last = *stack;
	while (last->next->next)
		last = last->next;
	ft_lstadd_front(stack, last->next);
	last->next = NULL;
	return (false);
}

bool	rra(t_stacks stacks)
{
	bool	error;

	error = reverse_rotate(stacks.a);
	if (!error)
		ft_putstr_fd("rra\n", 1);
	return (error);
}

bool	rrb(t_stacks stacks)
{
	bool	error;

	error = reverse_rotate(stacks.b);
	if (!error)
		ft_putstr_fd("rrb\n", 1);
	return (error);
}

bool	rrr(t_stacks stacks)
{
	bool	a_error;
	bool	b_error;

	a_error = reverse_rotate(stacks.a);
	b_error = reverse_rotate(stacks.b);
	if (!a_error && !b_error)
		ft_putstr_fd("rrr\n", 1);
	else if (!a_error)
		ft_putstr_fd("rra\n", 1);
	else if (!b_error)
		ft_putstr_fd("rrb\n", 1);
	return (a_error || b_error);
}

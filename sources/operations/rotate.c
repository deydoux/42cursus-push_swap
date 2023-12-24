/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:01:18 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/24 15:16:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return (true);
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	ft_lstadd_back(stack, last);
	return (false);
}

bool	ra(t_stacks stacks)
{
	bool	error;

	error = rotate(stacks.a);
	if (!error)
		ft_putstr_fd("ra\n", 1);
	return (error);
}

bool	rb(t_stacks stacks)
{
	bool	error;

	error = rotate(stacks.b);
	if (!error)
		ft_putstr_fd("rb\n", 1);
	return (error);
}

bool	rr(t_stacks stacks)
{
	bool	a_error;
	bool	b_error;

	a_error = rotate(stacks.a);
	b_error = rotate(stacks.b);
	if (!a_error && !b_error)
		ft_putstr_fd("rr\n", 1);
	else if (!a_error)
		ft_putstr_fd("ra\n", 1);
	else if (!b_error)
		ft_putstr_fd("rb\n", 1);
	return (a_error || b_error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:18:01 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/24 13:47:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!*stack || !(*stack)->next)
		return (true);
	first = *stack;
	second = first->next;
	third = second->next;
	*stack = second;
	second->next = first;
	first->next = third;
	return (false);
}

bool	sa(t_stacks stacks)
{
	bool	error;

	error = swap(stacks.a);
	if (!error)
		ft_putstr_fd("sa\n", 1);
	return (error);
}

bool	sb(t_stacks stacks)
{
	bool	error;

	error = swap(stacks.b);
	if (!error)
		ft_putstr_fd("sb\n", 1);
	return (error);
}

bool	ss(t_stacks stacks)
{
	bool	a_error;
	bool	b_error;

	a_error = swap(stacks.a);
	b_error = swap(stacks.b);
	if (!a_error && !b_error)
		ft_putstr_fd("ss\n", 1);
	else if (!a_error)
		ft_putstr_fd("sa\n", 1);
	else if (!b_error)
		ft_putstr_fd("sb\n", 1);
	return (a_error || b_error);
}

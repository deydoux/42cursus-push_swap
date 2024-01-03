/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:18:01 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 02:18:24 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*start;

	if (!*stack || !(*stack)->next)
		return ;
	start = (*stack)->next;
	(*stack)->next = start->next;
	ft_lstadd_front(stack, start);
}

void	sa(t_stacks stacks)
{
	ft_putstr_fd("sa\n", 1);
	swap(stacks.a);
}

void	sb(t_stacks stacks)
{
	ft_putstr_fd("sb\n", 1);
	swap(stacks.b);
}

void	ss(t_stacks stacks)
{
	ft_putstr_fd("ss\n", 1);
	swap(stacks.a);
	swap(stacks.b);
}

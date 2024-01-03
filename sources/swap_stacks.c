/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:18:01 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 17:58:15 by deydoux          ###   ########.fr       */
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

void	swap_a(t_stacks stacks)
{
	ft_putstr_fd("sa\n", 1);
	swap(stacks.a);
}

void	swap_b(t_stacks stacks)
{
	ft_putstr_fd("sb\n", 1);
	swap(stacks.b);
}

void	swap_stacks(t_stacks stacks)
{
	ft_putstr_fd("ss\n", 1);
	swap(stacks.a);
	swap(stacks.b);
}

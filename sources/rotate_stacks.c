/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:01:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 17:57:27 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	ft_lstadd_back(stack, last);
}

void	rotate_a(t_stacks stacks)
{
	ft_putstr_fd("ra\n", 1);
	rotate(stacks.a);
}

void	rotate_b(t_stacks stacks)
{
	ft_putstr_fd("rb\n", 1);
	rotate(stacks.b);
}

void	rotate_stacks(t_stacks stacks)
{
	ft_putstr_fd("rr\n", 1);
	rotate(stacks.a);
	rotate(stacks.b);
}

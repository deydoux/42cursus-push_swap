/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:19:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 02:17:31 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next->next)
		last = last->next;
	ft_lstadd_front(stack, last->next);
	last->next = NULL;
}

void	rra(t_stacks stacks)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate(stacks.a);
}

void	rrb(t_stacks stacks)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_rotate(stacks.b);
}

void	rrr(t_stacks stacks)
{
	ft_putstr_fd("rrr\n", 1);
	reverse_rotate(stacks.a);
	reverse_rotate(stacks.b);
}

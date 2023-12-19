/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:54:35 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/19 15:32:43 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_list *stack)
{
	void	*content;

	if (!stack || !stack->next)
		return (false);
	content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = content;
	return (true);
}

void	sa(t_list *stack)
{
	if (swap(stack))
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_list *stack)
{
	if (swap(stack))
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks stacks)
{
	if (!stacks.a)
		sb(stacks.b);
	else if (!stacks.b)
		sa(stacks.a);
	else
	{
		swap(stacks.a);
		swap(stacks.b);
		ft_putstr_fd("ss\n", 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:54:35 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/19 15:24:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stack)
{
	void	*content;

	if (!stack || !stack->next)
		return ;
	content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = content;
}

void	sa(t_list *stack)
{
	swap(stack);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list *stack)
{
	swap(stack);
	ft_putstr_fd("sb\n", 1);
}

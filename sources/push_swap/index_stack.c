/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:34:00 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/25 14:47:57 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem	*min_elem(t_list *stack)
{
	t_elem	*min;

	min = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (((t_elem *)stack->content)->value < min->value)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void	index_stack(t_list *stack, size_t size)
{
	t_elem	*min;
	size_t	index;

	min = min_elem(stack);
	min->index = 0;
	index = 1;
	while (index < size)
	{
		min = greater_elem(min->value, stack);
		min->index = index++;
	}
}

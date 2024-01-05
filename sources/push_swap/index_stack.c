/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:34:00 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 22:50:15 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*min_elem(t_list *stack)
{
	t_list	*min;

	min = stack;
	stack = stack->next;
	while (stack)
	{
		if (((t_elem *)stack->content)->value < ((t_elem *)min->content)->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	index_stack(t_list *stack)
{
	t_list	*min;
	size_t	index;
	size_t	size;

	min = min_elem(stack);
	((t_elem *)min->content)->index = 0;
	index = 1;
	size = ft_lstsize(stack);
	while (index < size)
	{
		min = elem_greater_than(((t_elem *)min->content)->value, stack);
		((t_elem *)min->content)->index = index++;
	}
}

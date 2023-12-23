/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:34:00 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/23 16:19:17 by deydoux          ###   ########.fr       */
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

static t_list	*relative_min_elem(int min_value, t_list *stack)
{
	t_list	*min;

	while (((t_elem *)stack->content)->value <= min_value)
		stack = stack->next;
	min = stack;
	stack = stack->next;
	while (stack)
	{
		if (((t_elem *)stack->content)->value < ((t_elem *)min->content)->value
			&& ((t_elem *)stack->content)->value > min_value)
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
		min = relative_min_elem(((t_elem *)min->content)->value, stack);
		((t_elem *)min->content)->index = index++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_greater_than.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:46:22 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 23:17:19 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*elem_greater_than(int value, t_list *stack)
{
	t_list	*elem;

	while (stack && ((t_elem *)stack->content)->value <= value)
		stack = stack->next;
	if (!stack)
		return (min_elem(stack));
	elem = stack;
	stack = stack->next;
	while (stack)
	{
		if (((t_elem *)stack->content)->value < ((t_elem *)elem->content)->value
			&& ((t_elem *)stack->content)->value > value)
			elem = stack;
		stack = stack->next;
	}
	return (elem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_greater_than.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:46:22 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 22:50:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*elem_greater_than(int value, t_list *stack)
{
	t_list	*min;

	while (((t_elem *)stack->content)->value <= value)
		stack = stack->next;
	min = stack;
	stack = stack->next;
	while (stack)
	{
		if (((t_elem *)stack->content)->value < ((t_elem *)min->content)->value
			&& ((t_elem *)stack->content)->value > value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

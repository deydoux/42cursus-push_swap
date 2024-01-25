/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:35:23 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/25 15:05:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*greater_elem(int value, t_list *stack)
{
	t_elem	*elem;

	while (stack && ((t_elem *)stack->content)->value <= value)
		stack = stack->next;
	if (!stack)
		return (NULL);
	elem = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (((t_elem *)stack->content)->value < elem->value
			&& ((t_elem *)stack->content)->value > value)
			elem = stack->content;
		stack = stack->next;
	}
	return (elem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:14:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 23:30:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*min_elem(t_list *stack)
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

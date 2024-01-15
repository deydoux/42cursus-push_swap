/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_reverse_rotations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:28:13 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/15 15:14:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*simulate_reverse_rotations(size_t n, t_list *stack)
{
	t_list	*start;
	t_list	*next;

	if (!stack)
		return (NULL);
	start = stack;
	next = stack;
	while (n--)
	{
		next = next->next;
		if (!next)
			next = stack;
	}
	while (next->next)
	{
		next = next->next;
		stack = stack->next;
		if (!stack)
			stack = start;
	}
	return (stack);
}

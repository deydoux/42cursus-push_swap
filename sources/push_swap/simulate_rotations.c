/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:19:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/15 07:27:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*simulate_rotations(size_t n, t_list *stack)
{
	t_list	*start;

	start = stack;
	while (n--)
	{
		stack = stack->next;
		if (!stack)
			stack = start;
	}
	return (stack);
}

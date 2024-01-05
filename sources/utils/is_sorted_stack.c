/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:51:57 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 22:40:04 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

bool	is_sorted_stack(t_list *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (((t_elem *)stack->content)->value
			> ((t_elem *)stack->next->content)->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

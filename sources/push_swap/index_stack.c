/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:34:00 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 23:14:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

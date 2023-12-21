/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:55:04 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/21 16:01:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_duplicates(t_list *stack)
{
	int		value;
	t_list	*tmp_stack;

	while (stack)
	{
		value = ((t_elem *)stack->content)->value;
		stack = stack->next;
		tmp_stack = stack;
		while (tmp_stack)
		{
			if (((t_elem *)tmp_stack->content)->value == value)
				return (true);
			tmp_stack = tmp_stack->next;
		}
	}
	return (false);
}

bool	init_stacks(int argc, char **argv, t_stacks *stacks)
{
	stacks->a = malloc(sizeof(t_list *));
	stacks->b = malloc(sizeof(t_list *));
	if (!stacks->a || !stacks->b)
		return (true);
	*stacks->a = NULL;
	*stacks->b = NULL;
	return (parse_args(argc, argv, stacks->a) || check_duplicates(*stacks->a));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:55:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 22:40:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

bool	init_stacks(int argc, char **argv, t_stacks *stacks)
{
	stacks->a = malloc(sizeof(t_list *));
	stacks->b = malloc(sizeof(t_list *));
	if (!stacks->a || !stacks->b)
		return (true);
	*stacks->a = NULL;
	*stacks->b = NULL;
	return (parse_args(argc, argv, stacks->a));
}

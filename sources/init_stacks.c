/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:55:04 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/20 13:58:21 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	init_stacks(int argc, char **argv, bool *error)
{
	t_stacks	stacks;

	stacks.a = malloc(sizeof(t_list *));
	stacks.b = malloc(sizeof(t_list *));
	if (!stacks.a || !stacks.b)
	{
		*error = true;
		return (stacks);
	}
	*stacks.a = parse_args(argc, argv, error);
	return (stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:00:57 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/20 14:04:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks stacks)
{
	if (stacks.a)
		ft_lstclear(stacks.a, free);
	if (stacks.b)
		ft_lstclear(stacks.b, free);
	free(stacks.a);
	free(stacks.b);
}

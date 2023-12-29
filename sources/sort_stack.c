/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:19:49 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/29 19:10:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks stacks)
{
	size_t	size;

	size = ft_lstsize(*stacks.a);
	if (size == 2)
	{
		sa(stacks);
		return ;
	}
	index_stack(*stacks.a);
	if (size == 3)
		sort_three(stacks);
}

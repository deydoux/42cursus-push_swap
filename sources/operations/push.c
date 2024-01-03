/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:33:21 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 02:17:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **src, t_list **dst)
{
	t_list	*new;

	if (!*src)
		return ;
	new = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, new);
}

void	pa(t_stacks stacks)
{
	ft_putstr_fd("pa\n", 1);
	push(stacks.b, stacks.a);
}

void	pb(t_stacks stacks)
{
	ft_putstr_fd("pb\n", 1);
	push(stacks.a, stacks.b);
}

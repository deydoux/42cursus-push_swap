/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:33:21 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/24 14:09:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	push(t_list **src, t_list **dst)
{
	t_list	*new;

	if (!*src)
		return (true);
	new = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, new);
	return (false);
}

bool	pa(t_stacks stacks)
{
	bool	error;

	error = push(stacks.b, stacks.a);
	if (!error)
		ft_putstr_fd("pa\n", 1);
	return (error);
}

bool	pb(t_stacks stacks)
{
	bool	error;

	error = push(stacks.a, stacks.b);
	if (!error)
		ft_putstr_fd("pb\n", 1);
	return (error);
}

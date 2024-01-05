/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:00:57 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 22:39:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	free_stacks(t_stacks stacks)
{
	ft_lstclear(stacks.a, free);
	ft_lstclear(stacks.b, free);
	free(stacks.a);
	free(stacks.b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:28:40 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/26 16:20:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	bool		exit_status;
	size_t		size;

	exit_status = init_stacks(argc - 1, argv + 1, &stacks);
	if (exit_status)
		ft_putstr_fd("Error\n", 2);
	else if (!is_sorted_stack(*stacks.a))
	{
		size = ft_lstsize(*stacks.a);
		if (size == 2)
			swap_a(stacks);
		else
		{
			index_stack(*stacks.a, size);
			sort(stacks, size);
		}
	}
	free_stacks(stacks);
	return (exit_status);
}

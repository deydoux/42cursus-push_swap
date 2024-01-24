/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:28:40 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/24 14:41:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stacks stacks)
{
	size_t	size;

	size = ft_lstsize(*stacks.a);
	if (size == 2)
		return (swap_a(stacks));
	index_stack(*stacks.a, size);
	if (size == 3)
		sort_three(stacks);
	else if (size == 5)
		sort_five(stacks);
	else
		chunks_sort(stacks, size);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	bool		exit_status;

	exit_status = init_stacks(argc - 1, argv + 1, &stacks);
	if (exit_status)
		ft_putstr_fd("Error\n", 2);
	else if (!is_sorted_stack(*stacks.a))
		sort_stack(stacks);
	free_stacks(stacks);
	exit(exit_status);
}

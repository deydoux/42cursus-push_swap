/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:41:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/26 17:44:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	put_error(t_stacks stacks)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(stacks);
	return (1);
}

static bool	switch_operation(char *operation, t_stacks stacks)
{
	if (!ft_strcmp(operation, "sa\n"))
		swap_a(stacks);
	else if (!ft_strcmp(operation, "sb\n"))
		swap_b(stacks);
	else if (!ft_strcmp(operation, "ss\n"))
		swap_stacks(stacks);
	else if (!ft_strcmp(operation, "pa\n"))
		push_a(stacks);
	else if (!ft_strcmp(operation, "pb\n"))
		push_b(stacks);
	else if (!ft_strcmp(operation, "ra\n"))
		rotate_a(stacks);
	else if (!ft_strcmp(operation, "rb\n"))
		rotate_b(stacks);
	else if (!ft_strcmp(operation, "rr\n"))
		rotate_stacks(stacks);
	else if (!ft_strcmp(operation, "rra\n"))
		reverse_rotate_a(stacks);
	else if (!ft_strcmp(operation, "rrb\n"))
		reverse_rotate_b(stacks);
	else if (!ft_strcmp(operation, "rrr\n"))
		reverse_rotate_stacks(stacks);
	else
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*operation;

	if (init_stacks(argc - 1, argv + 1, &stacks))
		return (put_error(stacks));
	operation = get_next_line(0);
	while (operation)
	{
		if (switch_operation(operation, stacks))
			return (put_error(stacks));
		free(operation);
		operation = get_next_line(0);
	}
	if (is_sorted_stack(*stacks.a) && !*stacks.b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stacks(stacks);
	return (0);
}

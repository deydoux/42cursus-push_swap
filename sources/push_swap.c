/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:28:40 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/23 15:56:37 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	bool		exit_status;

	exit_status = init_stacks(argc - 1, argv + 1, &stacks);
	if (!exit_status)
	{
		index_stack(*stacks.a);
	}
	else
		ft_putstr_fd("Error\n", 2);
	free_stacks(stacks);
	exit(exit_status);
}

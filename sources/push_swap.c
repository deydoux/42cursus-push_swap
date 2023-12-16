/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:28:40 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/16 19:31:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	bool		error;
	t_stacks	stacks;

	error = false;
	stacks.a = parse_args(argc - 1, argv + 1, &error);
	stacks.b = NULL;
	if (!error)
	{

	}
	else
		ft_putstr_fd("Error\n", 2);
	ft_lstclear(&stacks.a, free);
	ft_lstclear(&stacks.b, free);
	exit(error);
}

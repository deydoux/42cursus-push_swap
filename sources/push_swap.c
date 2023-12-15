/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:28:40 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/15 19:57:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_n_ptr(void *ptr)
{
	int	*n_ptr;

	n_ptr = ptr;
	printf("%d\n", *n_ptr);
}

int	main(int argc, char **argv)
{
	bool	error;
	t_list	*a;

	error = false;
	a = parse_args(argc - 1, argv + 1, &error);
	ft_lstiter(a, &print_n_ptr);
	if (error)
	{
		ft_lstclear(&a, NULL);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

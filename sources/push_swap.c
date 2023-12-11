/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:27:10 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/11 19:25:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_args(t_list **stack, int argc, char **argv)
{
	char	**splited_arg;

	if (!argc)
		return ;
	splited_arg = ft_split(*argv, ' ');
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;

	if (--argc <= 0)
		return (0);
	parse_args(&a_stack, argc, argv + 1);
}

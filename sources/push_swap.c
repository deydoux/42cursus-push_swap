/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:27:10 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/13 11:23:51 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*parse_arg(char *arg)
{
	int		sign;
	int		n;
	int		tmp_n;

	sign = 1;
	tmp_n = 0;
	n = 0;
	if (*arg == '-' || *arg == '+')
		sign -= 2 * (*arg++ == '-');
	while (ft_isdigit(*arg))
	{
		tmp_n = tmp_n * 10 + *arg++ - '0';
		if (n != tmp_n / 10)
			return (NULL);
		n = tmp_n;
	}
	if (*arg)
		return (NULL);
	return (ft_lstnew(&n));
}

static t_list	*parse_args(int argc, char **argv, bool *error)
{
	char	**splited_args;
	size_t	i;
	t_list	*arg;
	t_list	*stack;

	if (!argc)
		return (NULL);
	splited_args = ft_split(*argv, ' ');
	if (!splited_args)
		*error = true;
	i = 0;
	while (splited_args[i] && !*error)
	{
		arg = parse_arg(splited_args[i++]);
		if (!arg)
			*error = true;
		ft_lstadd_back(&stack, arg);
	}
	free_split(splited_args);
	if (!error)
		ft_lstadd_back(&stack, parse_args(argc - 1, argv + 1, error));
	return (stack);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	bool		error;

	error = false;
	stacks.a = parse_args(argc - 1, argv + 1, &error);
	printf("%d", error);
	if (error)
	{
		ft_lstclear(&(stacks.a), NULL);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	stacks.b = NULL;
	ft_lstclear(&(stacks.a), NULL);
	exit(EXIT_SUCCESS);
}

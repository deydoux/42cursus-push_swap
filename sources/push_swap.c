/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:28:40 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/13 19:39:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *parse_arg(char *arg, bool *error)
{
	t_list	*new;
	int		sign;
	int		tmp_n;
	int		n;

	new = NULL;
	sign = 1;
	tmp_n = 0;
	n = 0;
	if (*arg == '-' || *arg == '+')
		sign -= 2 * (*arg++ == '-');
	while (ft_isdigit(*arg))
	{
		tmp_n = tmp_n * 10 + *arg++ - '0';
		if (n != tmp_n / 10)
			break;
		n = tmp_n;
	}
	if (*arg)
		*error = true;
}

static t_list	*parse_args(int argc, char **argv, bool *error)
{
	char	**splitted_arg;
	t_list	*stack;
	size_t	i;

	if (!argc)
		return (NULL);
	splitted_arg = ft_split(*argv, ' ');
	if (!splitted_arg)
	{
		*error = true;
		return (NULL);
	}
	stack = NULL;
	i = 0;
	while (splitted_arg[i])
		ft_lstadd_back()
}

int	main(int argc, char **argv)
{
	bool		error;
	t_stacks	stacks;

	error = false;
	stacks.a = parse_args(argc - 1, argv + 1, &error);
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	stacks.b = NULL;
	exit(EXIT_SUCCESS);
}

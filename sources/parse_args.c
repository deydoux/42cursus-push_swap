/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:11:06 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/15 20:09:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*parse_arg(char *arg)
{
	int				*n;
	unsigned int	u;
	t_list			*new;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = 1;
	u = 0;
	new = NULL;
	if (*arg == '-' || *arg == '+')
		*n -= 2 * (*arg++ == '-');
	while (ft_isdigit(*arg))
	{
		u = u * 10 + *arg++ - '0';
		if (u > INT_MAX && (*n != -1 || u != (unsigned int)INT_MAX + 1))
			return (NULL);
	}
	if (!*arg)
	{
		*n *= u;
		new = ft_lstnew(n);
	}
	return (new);
}

t_list	*parse_args(int argc, char **argv, bool *error)
{
	char	**splitted_args;
	size_t	i;
	t_list	*new;
	t_list	*stack;

	if (!argc || *error)
		return (NULL);
	splitted_args = ft_split(*argv, ' ');
	if (!splitted_args)
	{
		*error = true;
		return (NULL);
	}
	i = 0;
	stack = NULL;
	while (splitted_args[i] && !*error)
	{
		new = parse_arg(splitted_args[i++]);
		*error = !new;
		ft_lstadd_back(&stack, new);
	}
	free_split(splitted_args);
	ft_lstadd_back(&stack, parse_args(argc - 1, argv + 1, error));
	return (stack);
}

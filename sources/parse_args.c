/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:11:06 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/21 15:02:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	atoi_safe(char *s, int *n)
{
	unsigned int	u;

	if (!s)
		return (true);
	*n = 1;
	u = 0;
	if (*s == '-' || *s == '+')
		*n -= 2 * (*s++ == '-');
	while (ft_isdigit(*s))
	{
		u = u * 10 + *s++ - '0';
		if (u > INT_MAX && (*n != -1 || u != (unsigned int)INT_MAX + 1))
			return (true);
	}
	*n *= u;
	return (*s != 0);
}

static bool	new_elem(char *arg, t_list **stack)
{
	t_elem	*elem;
	t_list	*new;

	elem = malloc(sizeof(t_elem));
	if (!elem || atoi_safe(arg, &elem->value))
		return (true);
	new = ft_lstnew(elem);
	if (!new)
		return (true);
	ft_lstadd_back(stack, new);
	return (false);
}

bool	parse_args(int argc, char **argv, t_list **stack)
{
	char	**splitted_args;
	size_t	i;
	bool	error;

	if (!argc)
		return (false);
	splitted_args = ft_split(*argv, ' ');
	if (!splitted_args)
		return (true);
	i = 0;
	error = 0;
	while (splitted_args[i] && !error)
		error = new_elem(splitted_args[i++], stack);
	free_split(splitted_args);
	if (error)
		return (true);
	return (parse_args(argc - 1, argv + 1, stack));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:35:42 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 23:16:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
# include "libft.h"
# include <stdbool.h>

typedef struct s_elem
{
	int		value;
	size_t	index;
}			t_elem;

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}			t_stacks;

void	free_stacks(t_stacks stacks);
bool	init_stacks(int argc, char **argv, t_stacks *stacks);
bool	is_sorted_stack(t_list *stack);
bool	parse_args(int argc, char **argv, t_list **stack);
void	push_a(t_stacks stacks);
void	push_b(t_stacks stacks);
void	rotate_a(t_stacks stacks);
void	rotate_b(t_stacks stacks);
void	rotate_stacks(t_stacks stacks);
void	reverse_rotate_a(t_stacks stacks);
void	reverse_rotate_b(t_stacks stacks);
void	reverse_rotate_stacks(t_stacks stacks);
void	swap_a(t_stacks stacks);
void	swap_b(t_stacks stacks);
void	swap_stacks(t_stacks stacks);

#endif

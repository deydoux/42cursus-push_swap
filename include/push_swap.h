/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:23:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/03 17:58:15 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

typedef void	(*t_operation)(t_stacks);

void	free_stacks(t_stacks stacks);
void	index_stack(t_list *stack);
bool	init_stacks(int argc, char **argv, t_stacks *stacks);
bool	is_sorted_stack(t_list *stack);
bool	parse_args(int argc, char **argv, t_list **stack);
void	sort_five(t_stacks stacks);
void	sort_three(t_stacks stacks);

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

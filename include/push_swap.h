/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:23:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/29 13:19:51 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "push_swap_utils.h"

typedef struct s_moves
{
	size_t	ra;
	size_t	rb;
	bool	rra;
	bool	rrb;
	size_t	sum;
}			t_moves;

t_moves	compute_moves(t_list *stack, t_stacks stacks, size_t position);
void	create_chunks(size_t size, t_stacks stacks);
t_elem	*greater_elem(int value, t_list *stack);
void	index_stack(t_list *stack, size_t size);
void	sort_stack(t_stacks stacks, size_t size);

#endif

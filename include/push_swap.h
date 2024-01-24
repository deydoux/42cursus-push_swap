/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:23:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/25 13:37:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "push_swap_utils.h"

# define MIN_CHUNK_SIZE 20
# define MAX_CHUNKS 11
# define CHUNKS 3

typedef struct s_elem
{
	int		value;
	size_t	index;
}			t_elem;

typedef struct s_moves
{
	size_t	ra;
	size_t	rb;
	bool	rra;
	bool	rrb;
	size_t	sum;
}			t_moves;

typedef void	(*t_operation)(t_stacks);

void	chunk_stack(size_t n, size_t size, t_stacks stacks);
void	chunks_sort(t_stacks stacks, size_t size);
void	index_stack(t_list *stack, size_t size);
void	sort_five(t_stacks stacks);
void	sort_three(t_stacks stacks);

#endif

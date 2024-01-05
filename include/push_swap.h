/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:23:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/05 23:16:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "push_swap_utils.h"

# define MIN_CHUNK_SIZE 20
# define MAX_CHUNKS 11

typedef void	(*t_operation)(t_stacks);

void	chunk_stack(size_t n, size_t size, t_stacks stacks);
void	chunks_sort(t_stacks stacks);
t_list	*elem_greater_than(int value, t_list *stack);
void	index_stack(t_list *stack);
t_list	*min_elem(t_list *stack);
void	sort_five(t_stacks stacks);
void	sort_three(t_stacks stacks, bool *b_sorted);

#endif

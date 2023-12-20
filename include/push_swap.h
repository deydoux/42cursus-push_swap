/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:23:10 by deydoux           #+#    #+#             */
/*   Updated: 2023/12/20 14:05:36 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdbool.h>

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}			t_stacks;

void		free_stacks(t_stacks stacks);
t_stacks	init_stacks(int argc, char **argv, bool *error);
t_list		*parse_args(int argc, char **argv, bool *error);

void		sa(t_list *stack);
void		sb(t_list *stack);
void		ss(t_stacks stacks);

#endif

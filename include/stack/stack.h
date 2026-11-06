/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:29:58 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:29:59 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "benchmark/benchmark.h"
# include <stdlib.h>

typedef struct s_Element
{
	int					data;
	int					index;
	struct s_Element	*next;
	struct s_Element	*prev;
}	t_Element;

typedef struct s_Stack
{
	t_Element		*start;
	t_Element		*top;
	t_benchmark		*benchmark;
}	t_Stack;

t_Element	*create_element(int data, int index);
void		initialize_stack(t_Stack *stack);
void		clear_stack(t_Stack *stack);
void		rank_data(t_Stack *stack);
char		is_empty(t_Stack *stack);
void		push(t_Stack *stack, int data, int index);
void		pop(t_Stack *stack);
int			size(t_Stack *stack);
int			find_min_position(t_Stack *stack);
int			find_max_rank_position(t_Stack *stack);
void		iterate(t_Stack *stack, void (*f)(t_Element *));
void		display_full_stack(t_Stack *stack);
void		display_stack(t_Stack *stack);
double		compute_disorder(t_Stack *stack);

#endif

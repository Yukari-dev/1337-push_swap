/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:28:06 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:28:08 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

# include "stack/stack.h"

void	rotate(t_Stack *stack);
void	reverse_rotate(t_Stack *stack);
void	ra(t_Stack *a);
void	rb(t_Stack *b);
void	rr(t_Stack *a, t_Stack *b);
void	rra(t_Stack *a);
void	rrb(t_Stack *b);
void	rrr(t_Stack *a, t_Stack *b);

#endif

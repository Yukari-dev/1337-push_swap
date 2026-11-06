/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:27:02 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:27:02 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "stack/stack.h"

void	rotate_till(t_Stack *stack, int times, void (*rotate)(t_Stack *stack));
void	selection_sort(t_Stack *a, t_Stack *b);
void	chunk_sort(t_Stack *a, t_Stack *b, int chunk_size);
void	radix_sort(t_Stack *a, t_Stack *b);

#endif

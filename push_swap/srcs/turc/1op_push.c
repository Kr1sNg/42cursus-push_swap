/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1op_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 20:53:24 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//push: pa, pb: take the first element at the top of b/a and put it at the top of a /b
static void	push(t_stack **dest, t_stack **src) //OK
{
	t_stack	*push_node;
	
	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL; //it always at the top of stack so ->prev always = 0
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool print) //checked
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool print) //checked
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}


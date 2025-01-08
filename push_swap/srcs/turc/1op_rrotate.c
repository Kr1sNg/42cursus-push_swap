/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1op_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 20:48:12 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// rra, rrb, rrr: shift down all element by 1. The last become the first

static void	rev_rotate(t_stack **head) //OK
{
	t_stack	*tail;
	
	if (!*head || !(*head)->next)
		return;
	tail = ft_stack_last(*head);
	tail->prev->next = NULL;
	tail->next = *head;
	tail->prev = NULL;
	*head = tail;
	tail->next->prev = tail;
}

void	rra(t_stack **a, bool print) //OK
{
	rev_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print) //OK
{
	rev_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print) //OK
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		ft_printf("rrr\n");
}

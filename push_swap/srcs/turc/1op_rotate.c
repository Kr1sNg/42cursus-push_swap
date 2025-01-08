/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1op_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 20:49:44 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//rotate: ra, rb, rr: shift up all element by 1. The first become the last

static void	rotate(t_stack **head) //OK
{
	t_stack	*tail;

	if (!*head || !(*head)->next)
		return;
	tail = ft_stack_last(*head);
	tail->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
}

void	ra(t_stack **a, bool print) //checked
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print) //checked
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print) //checked
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}

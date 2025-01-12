/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/09 17:32:20 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ra: Shift up all elems of stack a by 1. The first elem becomes the last.
** rb: Shift up all elems of stack b by 1. The first elem becomes the last.
** rr: ra and rb at the same time.
*/

#include "../../includes/push_swap.h"

void	ft_rotate(t_stack **head)
{
	t_stack	*tail;

	if (*head == NULL || !(*head)->next)
		return ;
	tail = ft_stack_last(*head);
	tail->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
}

void	ra(t_stack **a, bool print)
{
	ft_rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print)
{
	ft_rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (print)
		ft_printf("rr\n");
}

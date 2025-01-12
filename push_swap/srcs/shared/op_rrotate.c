/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/09 17:32:32 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rra: Shift down all elems of stack a by 1.
** rrb: Shift down all elems of stack b by 1.
**				The last elem becomes the first one.
** rrr: rra and rrb at the same time.
*/

#include "../../includes/push_swap.h"
#include "../../includes/checker.h"

void	ft_rev_rotate(t_stack **head)
{
	t_stack	*tail;

	if (*head == NULL || !(*head)->next)
		return ;
	tail = ft_stack_last(*head);
	tail->prev->next = NULL;
	tail->next = *head;
	tail->prev = NULL;
	*head = tail;
	tail->next->prev = tail;
}

void	rra(t_stack **a, bool print)
{
	ft_rev_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	ft_rev_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	if (print)
		ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/09 17:31:03 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sa: Swap the first 2 elems at the top of stack a
** sb: Swap the first 2 elems at the top of stack b
** 			Do nothing if there is only one or no elements
** ss: sa and sb at the same time
*/

#include "../../includes/push_swap.h"

void	ft_swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, bool print)
{
	ft_swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool print)
{
	ft_swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	ft_swap(a);
	ft_swap(b);
	if (print)
		ft_printf("ss\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/09 17:34:32 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pa: take the first element at the top of b and put it at the top of a
** pb: take the first element at the top of a and put it at the top of b
*/

#include "../../includes/push_swap.h"
#include "../../includes/checker.h"

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;

	if (*src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dest == NULL)
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

void	pa(t_stack **a, t_stack **b, bool print)
{
	ft_push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	ft_push(b, a);
	if (print)
		ft_printf("pb\n");
}

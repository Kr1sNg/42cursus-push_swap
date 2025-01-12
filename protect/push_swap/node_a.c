/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:26:24 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/10 13:47:17 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_node_set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = ft_stack_size(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	ft_set_target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	t_stack	*target;
	long	best_match;

	while (a != NULL)
	{
		best_match = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if ((curr_b->nbr < a->nbr) && (curr_b->nbr > best_match))
			{
				best_match = curr_b->nbr;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = ft_stack_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	ft_cost_analysis(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_size(a);
	len_b = ft_stack_size(b);
	while (a != NULL)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	ft_set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (stack == NULL)
		return ;
	cheapest_value = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_node_init_a(t_stack *a, t_stack *b)
{
	ft_node_set_index(a);
	ft_node_set_index(b);
	ft_set_target_node_a(a, b);
	ft_cost_analysis(a, b);
	ft_set_cheapest(a);
}

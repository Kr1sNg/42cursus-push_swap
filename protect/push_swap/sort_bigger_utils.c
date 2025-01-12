/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:49:04 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/10 13:47:04 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, true);
	ft_node_set_index(*a);
	ft_node_set_index(*b);
}

void	ft_rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node-> target && *a != cheapest_node)
		rrr(a, b, true);
	ft_node_set_index(*a);
	ft_node_set_index(*b);
}

void	ft_move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_call_cheapest_node(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		ft_rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		ft_rev_rotate_both(a, b, cheapest_node);
	ft_prep_push(a, cheapest_node, 'a');
	ft_prep_push(b, cheapest_node->target, 'b');
	pb(b, a, true);
}

void	ft_move_b_to_a(t_stack **a, t_stack **b)
{
	ft_prep_push(a, (*b)->target, 'a');
	pa(a, b, true);
}

void	ft_move_min_to_top(t_stack **a)
{
	t_stack	*min_node;

	min_node = ft_stack_min(*a);
	while ((*a)->nbr != min_node->nbr)
	{
		if (min_node->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

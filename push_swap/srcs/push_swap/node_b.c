/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:26:24 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/10 13:47:30 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_set_target_node_b(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*target;
	long	best_match;

	while (b != NULL)
	{
		best_match = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if ((curr_a->nbr > b->nbr) && (curr_a->nbr < best_match))
			{
				best_match = curr_a->nbr;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = ft_stack_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	ft_node_init_b(t_stack *a, t_stack *b)
{
	ft_node_set_index(a);
	ft_node_set_index(b);
	ft_set_target_node_b(a, b);
}


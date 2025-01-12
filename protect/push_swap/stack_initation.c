/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:02 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/10 13:48:23 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_stack_add_back(t_stack **head, int nb)
{
	t_stack	*new;
	t_stack	*tail;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->next = NULL;
	new->nbr = nb;
	new->cheapest = false;
	new->push_cost = 0;
	new->index = 0;
	new->above_median = false;
	if (*head == NULL)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		tail = ft_stack_last(*head);
		tail->next = new;
		new->prev = tail;
	}
}

void	ft_stack_init(t_stack **stack, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_error_input(argv[i]))
			ft_exit(stack);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_exit(stack);
		if (ft_error_dup(*stack, (int)n))
			ft_exit(stack);
		ft_stack_add_back(stack, (int)n);
		i++;
	}
}
t_stack	*ft_call_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_prep_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

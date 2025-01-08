/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:45:02 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 21:14:29 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_add_back(t_stack **head, int nb)
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
	if (!(*head))
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

void	init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_input(argv[i]))
			free_exit(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_exit(a);
		if (error_dup(*a, (int)n)) //TODO
            free_exit(a);
		stack_add_back(a, (int)n); // list_add_back to have first argument be at the top of stack
		i++;
	}
}
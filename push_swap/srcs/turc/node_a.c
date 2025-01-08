/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:26:24 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 19:44:40 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    current_index(t_stack *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = ft_stack_len(stack) / 2;
    while (stack)
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

static void set_target_a(t_stack *a, t_stack *b)
{
    t_stack *curr_b;
    t_stack *target_node;
    long    best_match_index;

    while (a)
    {
        best_match_index = LONG_MIN;
        curr_b = b;
        while (curr_b)
        {
            if ((curr_b->nbr < a->nbr) && (curr_b->nbr > best_match_index))
            {
                best_match_index = curr_b->nbr;
                target_node = curr_b;
            }
            curr_b = curr_b->next;
        }
        if (best_match_index == LONG_MIN)
            a->target_node = find_max(b);
        else
            a->target_node = target_node;
        a = a->next;
    }
}

static void cost_analysis_a(t_stack *a, t_stack *b)
{
    int len_a;
    int len_b;
    
    len_a = ft_stack_len(a);
    len_b = ft_stack_len(b);
    while (a)
    {
        a->push_cost = a->index;
        if (!(a->above_median))
            a->push_cost = len_a - (a->index);
        if (a->target_node->above_median)
            a->push_cost += a->target_node->index;
        else
            a->push_cost += len_b - (a->target_node->index);
        a = a->next;
    }
}

static void    set_cheapest(t_stack *stack)
{
    long    cheapest_value;
    t_stack *cheapest_node;

    if (!stack)
        return;
    cheapest_value = LONG_MAX;
    while (stack != NULL)
    {
        if(stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = true;
}

void    init_nodes_a(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_analysis_a(a, b);
    set_cheapest(a);
}


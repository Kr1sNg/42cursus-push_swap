/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:49:04 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/07 20:13:15 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void move_a_to_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest_node;

    cheapest_node = get_cheapest(*a); //TODO
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a, b, cheapest_node); //TODO
    else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
        rev_rotate_both(a, b, cheapest_node); //TODO
    prep_for_push(a, cheapest_node, 'a'); //TODO
    prep_for_push(b, cheapest_node->target_node, 'b');
    pb(b, a, true); //TODO
}

static void move_b_to_a(t_stack **a, t_stack **b)
{
    prep_for_push(a, (*b)->target_node, 'a');
    pa(a, b, true);
}

static void min_on_top(t_stack **a)
{
    t_stack *min_node;
    
    min_node = find_min(*a);
    while ((*a)->nbr != min_node->nbr)
    {
        if (min_node->above_median)
            ra(a, true);
        else
            rra(a, true);
    }
}

void    sort_stacks(t_stack **a, t_stack **b)
{
    int len_a;

    len_a = stack_len(*a); //TODO
    if ((len_a - 1 > 3) && !is_stack_sorted(*a))
        pb(b, a, true);
    if ((len_a - 1 > 3) && !is_stack_sorted(*a))
        pb(b, a, true);
    while ((len_a - 1 > 3) && !is_stack_sorted(*a))
    {
        init_nodes_a(*a, *b);
        move_a_to_b(a, b);
    }
    sort_three(a);
    while (*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}
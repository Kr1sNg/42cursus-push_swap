/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:26:24 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 18:39:38 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void set_target_b(t_stack *a, t_stack *b)
{
    t_stack *curr_a;
    t_stack *target_node;
    long    best_match_index;

    while (b)
    {
        best_match_index = LONG_MAX;
        curr_a = a;
        while (curr_a)
        {
            if ((curr_a->nbr > b->nbr) && (curr_a->nbr < best_match_index))
            {
                best_match_index = curr_a->nbr;
                target_node = curr_a;
            }
            curr_a = curr_a->next;
        }
        if (best_match_index == LONG_MAX)
            b->target_node = find_min(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

void    init_nodes_b(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}


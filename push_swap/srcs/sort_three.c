/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:49:04 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/07 16:51:02 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_three(t_stack **a)
{
    t_stack *biggest_node;

    biggest_node = find_max(*a); //TODO
    if (biggest_node == *a)
        ra(a, false); //TODO
    else if (biggest_node == (*a)->next)
        rra(a, false); //TODO
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false); //TODO
}

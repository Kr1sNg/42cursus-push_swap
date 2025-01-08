/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:13 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 20:10:47 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long ft_atol(char *s)
{
    int     i;
    long    l;
    int     sign;
    
    i = 0;
    l = 0;
    sign = 1;
    while (ft_isspace(s[i]))
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        l = l * 10 + (s[i] - '0');
        i++;
    }
    return (l * sign);
}

int ft_stack_len(t_stack *head)
{
    int i;

    if (!head)
        return (0);
    i = 0;
    while (head)
    {
        head = head->next;
        i++;
    }
    return (i);
}

t_stack *ft_stack_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

t_stack *find_min(t_stack *stack)
{
    long    min;
    t_stack *min_node;

    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->nbr < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}

t_stack *find_max(t_stack *stack)
{
    long    max;
    t_stack *max_node;
    
    if (!stack)
        return (NULL);
    max = LONG_MIN;
    while (stack)
    {
        if (stack->nbr > max)
        {
            max = stack->nbr;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}
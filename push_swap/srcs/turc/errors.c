/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:24:48 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 18:53:14 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
// return -42 means ERROR, 0 means OK
int error_input(char *str)
{
    int i;

    if (!(str[0] == '+' || str[0] == '-' || ft_isdigit(str[0])))
        return (-42);
    if ((str[0] == '+' || str[0] == '-'))
    {
        if (!ft_isdigit(str[1]))
            return (-42);
    }
    i = 1;
    while (str[i] != '\0')
    {
        if (!(ft_isdigit(str[i])))
            return (-42);
        i++;
    }
    return (0);
}

int error_dup(t_stack *a, int n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->nbr == n)
            return (-42);
        a = a->next;
    }
    return (0);
}

void    free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *curr;

    if (!stack)
        return ;
    curr = *stack;
    while (curr)
    {
        tmp = curr->next;
        curr->nbr = 0;
        free(curr);
        curr = tmp;
    }
    *stack = NULL;
}

void    free_exit(t_stack **a)
{
    free_stack(a);
    ft_printf("Error\n");
    exit(EXIT_FAILURE);
}


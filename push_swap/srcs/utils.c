/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:13 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/07 15:23:00 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
        i++;
        if (s[i] == '-')
            sign = -1;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        l = l * 10 + (s[i] - '0');
        i++;
    }
    return (l * sign);
}

// #include <stdio.h>
// int main(void)
// {
//     char *s = "-214748364700000";
//     printf("%ld\n", ft_atol(s));
// }
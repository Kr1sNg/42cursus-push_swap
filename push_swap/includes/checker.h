/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:39:57 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/10 13:47:17 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** :::::::::::::::::::::::::::::::::* HEADERS *:::::::::::::::::::::::::::::: **
*/

# include "../libft/includes/libft.h"
# include "shared.h"
# include <stdbool.h>
# include <limits.h>

/*
** :::::::::::::::::::::::::::* STRUCT DECLARATION *::::::::::::::::::::::::: **
*/

// typedef struct s_stack
// {
// 	int				nbr;
// 	int				index;
// 	int				push_cost;
// 	bool			above_median;
// 	bool			cheapest;
// 	struct s_stack	*target;
// 	struct s_stack	*next;
// 	struct s_stack	*prev;
// }	t_stack;

/*
** ::::::::::::::::::::::::::* FUNCTION PROTOTYPES *::::::::::::::::::::::::: **
*/

/*
**	Checker
**	checker.c
*/

int		ft_iserrorop(char *op, t_stack **a, t_stack **b);
int		ft_execuse(t_list *instruction, t_stack **a, t_stack **b);
void	read_and_execute(int fd, t_stack **a, t_stack **b);

#endif

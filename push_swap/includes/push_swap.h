/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:39:57 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/05 12:53:22 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** :::::::::::::::::::::::::::::::::* HEADERS *:::::::::::::::::::::::::::::: **
*/

# include "../libft/includes/libft.h"
# include <stdbool.h>
# include <limits.h>

/*
** :::::::::::::::::::::::::::* STRUCT DECLARATION *::::::::::::::::::::::::: **
*/

typedef	struct s_stack_node
{
	int		nbr;
	int		index;
	int 	push_cost;
	bool	above_equator;
	bool	cheapest;

	struct s_stack_node *target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;


/*
** ::::::::::::::::::::::::::* FUNCTION PROTOTYPES *::::::::::::::::::::::::: **
*/

/*
**	Handle errors
*/

/*
**	Stack initiation
*/

/*
**	Node initiation
*/

/*
**	Stack utils
*/

/*
**	Operation commands
*/

/*
**	Algorithms
*/

/*
**	Other
*/

#endif
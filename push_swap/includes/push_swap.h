/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:39:57 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 21:37:32 by tat-nguy         ###   ########.fr       */
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

typedef	struct s_stack
{
	int		nbr;
	int		index;
	int 	push_cost;
	bool	above_median;
	bool	cheapest;

	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


/*
** ::::::::::::::::::::::::::* FUNCTION PROTOTYPES *::::::::::::::::::::::::: **
*/

/*
**	Handle errors
*/

int		error_input(char *str);
int		error_dup(t_stack *a, int n);
void    free_stack(t_stack **stack);
void    free_exit(t_stack **a);

/*
**	Node initiation
*/

void    current_index(t_stack *stack);
void    init_nodes_a(t_stack *a, t_stack *b);
void    init_nodes_b(t_stack *a, t_stack *b);


/*
**	Stack utils
*/

void	init_stack_a(t_stack **a, char **argv);
void	stack_add_back(t_stack **head, int n);
bool	is_stack_sorted(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);

/*
**	Operation commands
*/

void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);


/*
**	Algorithms
*/

void    sort_stacks(t_stack **a, t_stack **b);
void    sort_three(t_stack **a);

/*
**	Other
*/

long	ft_atol(char *s);
int		ft_stack_len(t_stack *head);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);



#endif
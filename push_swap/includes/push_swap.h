/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:39:57 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/10 13:49:30 by tat-nguy         ###   ########.fr       */
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

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*
** ::::::::::::::::::::::::::* FUNCTION PROTOTYPES *::::::::::::::::::::::::: **
*/

/*
**	Algorithms
**	push_swap.c 
*/

void	ft_sorting(t_stack **a, t_stack **b);
void	ft_sort_three(t_stack **a);
void	ft_sort_bigger(t_stack **a, t_stack **b);

/*
**	Sorting stack bigger than 3
**	sort_bigger.c 
*/

void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	ft_rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	ft_move_a_to_b(t_stack **a, t_stack **b);
void	ft_move_b_to_a(t_stack **a, t_stack **b);
void	ft_move_min_to_top(t_stack **a);

/*
**	Errors handling
**	error.c
*/

int		ft_error_input(char *str);
int		ft_error_dup(t_stack *a, int n);
void	ft_stack_clear(t_stack **stack);
void	ft_exit(t_stack **a);

/*
**	Nodes handling
**	node_a.c node_b.c
*/

void	ft_node_set_index(t_stack *stack);
void	ft_set_target_node_a(t_stack *a, t_stack *b);
void	ft_cost_analysis(t_stack *a, t_stack *b);
void	ft_set_cheapest(t_stack *stack);
void	ft_node_init_a(t_stack *a, t_stack *b);

void	ft_set_target_node_b(t_stack *a, t_stack *b);
void	ft_node_init_b(t_stack *a, t_stack *b);

/*
**	Stack initation
**	stack_initation.c
*/

void	ft_stack_add_back(t_stack **head, int nb);
void	ft_stack_init(t_stack **stack, char **argv);
t_stack	*ft_call_cheapest_node(t_stack *stack);
void	ft_prep_push(t_stack **stack, t_stack *top_node, char stack_name);

/*
**	Stack utils
**	stack_utils.c
*/

bool	ft_isstacksorted(t_stack *stack);
int		ft_stack_size(t_stack *head);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_min(t_stack *stack);
t_stack	*ft_stack_max(t_stack *stack);

/*
**	Operation commands
**	op_push.c op_rotate.c op_rrotate.c op_swap.c
*/

void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

/*
**	Operation utils
**	op_push.c op_rotate.c op_rrotate.c op_swap.c
*/

void	ft_swap(t_stack **head);
void	ft_push(t_stack **dest, t_stack **src);
void	ft_rotate(t_stack **head);
void	ft_rev_rotate(t_stack **head);

#endif
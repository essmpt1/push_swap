/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:02:04 by malourei          #+#    #+#             */
/*   Updated: 2024/11/07 18:48:04 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

t_list	*new_node(int value);
void	ft_push(t_list **stack, int value);
void	ft_free_list(t_list **stack);
int		is_sorted(t_list **stack);
int		ft_size(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ft_sort_3(t_list **stack);
void	ft_sort_4(t_list **stack, t_list **stack_b);
void	ft_sort_5(t_list **stack, t_list **stack_b);
void	valide_args(char **args, t_list **numbers, int argc);
void	ft_init_sort(t_list **stack_a, t_list **stack_b);
void	ft_print_list(t_list *stack);

#endif

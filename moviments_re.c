/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments_re.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:42:31 by malourei          #+#    #+#             */
/*   Updated: 2024/10/30 22:48:09 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_help(t_list **stack)
{
	t_list	*penultimo;
	t_list	*ultimo;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	penultimo = NULL;
	ultimo = *stack;
	while (ultimo->next)
	{
		penultimo = ultimo;
		ultimo = ultimo->next;
	}
	penultimo->next = NULL;
	ultimo->next = *stack;
	*stack = ultimo;
}

void	reverse_rotate_a(t_list **stack_a)
{
	reverse_rotate_help(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **stack_b)
{
	reverse_rotate_help(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_help(stack_a);
	reverse_rotate_help(stack_b);
	write(1, "rrr\n", 4);
}

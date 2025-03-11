/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:21:48 by malourei          #+#    #+#             */
/*   Updated: 2024/11/07 19:15:56 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_list **stack)
{
	t_list	*list;
	int		a;
	int		b;
	int		count;

	list = *stack;
	count = 0;
	b = 0;
	a = list->value;
	while (list)
	{
		if (a > list->value)
		{
			a = list->value;
			b = count;
		}
		list = list->next;
		count++;
	}
	return (b);
}

void	ft_sort_3(t_list **stack)
{
	t_list	*list;
	int		first;
	int		second;
	int		third;

	list = *stack;
	first = list->value;
	second = list->next->value;
	third = list->next->next->value;
	if ((first > second) && (first > third) && (second > third))
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else if ((first > second) && (first > third) && (second < third))
		rotate_a(stack);
	else if ((first < second) && (first > third) && second > third)
		reverse_rotate_a(stack);
	else if ((first > second) && (first < third) && second < third)
		swap_a(stack);
	else
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

void	ft_sort_4(t_list **stack, t_list **stack_b)
{
	int		index_min;

	if (is_sorted(stack))
		return ;
	index_min = find_min(stack);
	if (index_min == 1)
		rotate_a(stack);
	else if (index_min == 2)
	{
		rotate_a(stack);
		rotate_a(stack);
	}
	else if (index_min == 3)
		reverse_rotate_a(stack);
	if (is_sorted(stack))
	{
		push_a(stack, stack_b);
		return ;
	}
	push_b(stack, stack_b);
	ft_sort_3(stack);
	push_a(stack, stack_b);
}

void	ft_sort_5(t_list **stack, t_list **stack_b)
{
	int	index_min;

	index_min = find_min(stack);
	if (index_min == 1)
		rotate_a(stack);
	else if (index_min == 2)
	{
		rotate_a(stack);
		rotate_a(stack);
	}
	else if (index_min == 3)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
	else if (index_min == 4)
		reverse_rotate_a(stack);
	push_b(stack, stack_b);
	ft_sort_4(stack, stack_b);
	push_a(stack, stack_b);
}

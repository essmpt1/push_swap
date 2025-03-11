/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:12:59 by malourei          #+#    #+#             */
/*   Updated: 2024/11/05 18:37:16 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_menor_numero(t_list **stack)
{
	t_list	*tmp;
	int		temp;

	tmp = *stack;
	temp = tmp->value;
	while (tmp)
	{
		if (tmp->value == temp && tmp->index > 0)
			if (tmp->next)
				temp = tmp->next->value;
		if (temp > tmp->value && tmp->index == 0)
			temp = tmp->value;
		tmp = tmp->next;
	}
	return (temp);
}

static void	init_index(t_list **stack)
{
	t_list			*temp;
	int				size;
	static int		index;
	int				menor_num;

	temp = *stack;
	size = ft_size(stack);
	menor_num = get_menor_numero(stack);
	while (size > 0)
	{
		while (temp)
		{
			if (temp->value == menor_num && temp->index == 0)
			{
				index++;
				temp->index = index;
				menor_num = get_menor_numero(stack);
			}
			temp = temp->next;
		}
		size--;
	}
}

static int	ft_radix(t_list **a)
{
	int		value;
	int		bits;
	t_list	*tmp;

	value = (*a)->index;
	bits = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index > value)
			value = tmp->index;
		tmp = tmp->next;
	}
	while ((value >> bits) != 0)
		bits++;
	return (bits);
}

static void	ft_sort_radix(t_list **a, t_list **b)
{
	int	bits;
	int	i;
	int	j;
	int	stack_size;

	i = 0;
	bits = ft_radix(a);
	stack_size = ft_size(a);
	while (i < bits)
	{
		j = 0;
		while (j < stack_size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				rotate_a(a);
			else
				push_b(a, b);
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}

void	ft_init_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a))
		return ;
	size = ft_size(stack_a);
	while (size > 0)
	{
		init_index(stack_a);
		size--;
	}
	ft_sort_radix(stack_a, stack_b);
}

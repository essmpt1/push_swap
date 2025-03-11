/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:09:00 by malourei          #+#    #+#             */
/*   Updated: 2024/11/07 20:25:39 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int value)
{
	t_list	*node;

	node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!node)
	{
		write(2, "ERROR\n", 6);
		return (NULL);
	}
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_push(t_list **stack, int value)
{
	t_list	*node;
	t_list	*list;

	node = new_node(value);
	if (!node)
		return ;
	node->index = 0;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	list = *stack;
	while (list->next)
		list = list->next;
	list->next = node;
}

int	ft_size(t_list **stack)
{
	t_list	*s;
	int		i;

	i = 0;
	s = *stack;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

void	ft_free_list(t_list **stack)
{
	t_list	*temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	is_sorted(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack;
	while (temp1->next)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->value > temp2->value)
				return (0);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (1);
}

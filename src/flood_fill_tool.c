/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:10 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:38:11 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_directions(int *dxy)
{
	dxy[0] = 1;
	dxy[1] = 0;
	dxy[2] = -1;
	dxy[3] = 0;
	dxy[4] = 0;
	dxy[5] = 1;
	dxy[6] = 0;
	dxy[7] = -1;
}

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->x = malloc(size * sizeof(int));
	stack->y = malloc(size * sizeof(int));
	if (!stack->x || !stack->y)
	{
		free(stack->x);
		free(stack->y);
		free(stack);
		return (NULL);
	}
	stack->size = size;
	stack->top = -1;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->x);
	free(stack->y);
	free(stack);
}

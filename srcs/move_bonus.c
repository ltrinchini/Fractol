/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:00:30 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/25 23:04:12 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol_bonus.h"

void	ft_move_right(t_limit *limit)
{
	float	range_x;

	range_x = limit->x_max - limit->x_min;
	if (range_x > DELTA)
	{
		limit->x_max += range_x * SPEED_MOVE;
		limit->x_min += range_x * SPEED_MOVE;
	}
}

void	ft_move_left(t_limit *limit)
{
	float	range_x;

	range_x = limit->x_max - limit->x_min;
	if (range_x > DELTA)
	{
		limit->x_max -= range_x * SPEED_MOVE;
		limit->x_min -= range_x * SPEED_MOVE;
	}
}

void	ft_move_up(t_limit *limit)
{
	float	range_y;

	range_y = limit->y_max - limit->y_min;
	if (range_y > DELTA)
	{
		limit->y_max -= range_y * SPEED_MOVE;
		limit->y_min -= range_y * SPEED_MOVE;
	}
}

void	ft_move_down(t_limit *limit)
{
	float	range_y;

	range_y = limit->y_max - limit->y_min;
	if (range_y > DELTA)
	{
		limit->y_max += range_y * SPEED_MOVE;
		limit->y_min += range_y * SPEED_MOVE;
	}
}

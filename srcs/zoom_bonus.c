/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:09:42 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/25 23:04:29 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol_bonus.h"

void	ft_zoom_out(t_limit *limite)
{
	double	range_x;
	double	range_y;

	range_x = limite->x_max - limite->x_min;
	limite->x_max += range_x * SPEED_ZOOM;
	limite->x_min -= range_x * SPEED_ZOOM;
	range_y = limite->y_max - limite->y_min;
	limite->y_max += range_y * SPEED_ZOOM;
	limite->y_min -= range_y * SPEED_ZOOM;
}

void	ft_zoom(t_limit *limite, int x, int y)
{
	float	range_x;
	float	range_y;
	double	temp;

	range_x = limite->x_max - limite->x_min;
	range_y = limite->y_max - limite->y_min;
	if (range_x > EPSILON && range_y > EPSILON)
	{
		limite->x_max -= range_x * SPEED_ZOOM;
		limite->x_min += range_x * SPEED_ZOOM;
		limite->y_max -= range_y * SPEED_ZOOM;
		limite->y_min += range_y * SPEED_ZOOM;
		if (x > 0 && x < WIDTH_WINDOW && y > 0 && y < HEIGHT_WINDOW)
		{
			temp = ((double)x - (WIDTH_WINDOW / 2)) / (WIDTH_WINDOW / 2);
			limite->x_max += (temp * range_x * SPEED_MOVE);
			limite->x_min += (temp * range_x * SPEED_MOVE);
			temp = ((double)y - (HEIGHT_WINDOW / 2)) / (HEIGHT_WINDOW / 2);
			limite->y_max += (SPEED_MOVE * range_y * temp);
			limite->y_min += (SPEED_MOVE * range_y * temp);
		}
	}
}

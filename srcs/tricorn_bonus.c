/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:19:27 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/25 23:04:18 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol_bonus.h"

static t_scale	ft_scale(t_limit lim)
{
	t_scale	scale;

	scale.x = WIDTH_WINDOW / (lim.x_max - lim.x_min);
	scale.y = HEIGHT_WINDOW / (lim.y_max - lim.y_min);
	return (scale);
}

static int	ft_tricorn(t_coord img, t_scale scale, t_mlx mlx)
{
	t_nb_cmplx		c;
	t_nb_cmplx		z;
	double			temp;
	unsigned int	i;

	c.r = img.x / scale.x + mlx.limit->x_min;
	c.i = img.y / scale.y + mlx.limit->y_min;
	z.r = c.r;
	z.i = c.i;
	i = 1;
	while (((z.r * z.r + z.i * z.i) < 4) && (i < *mlx.precision))
	{
		temp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = -2 * z.i * temp + c.i;
		i++;
	}
	ft_draw(mlx, img, i);
	return (0);
}

int	ft_call_tricorn(t_mlx mlx)
{
	t_coord	img;

	img.x = 0;
	while (img.x < WIDTH_WINDOW)
	{
		img.y = 0;
		while (img.y < HEIGHT_WINDOW)
		{
			ft_tricorn(img, ft_scale(*mlx.limit), mlx);
			img.y++;
		}
		img.x++;
	}
	return (0);
}

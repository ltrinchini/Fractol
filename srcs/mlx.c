/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:27:23 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/25 16:27:15 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol.h"

int	ft_close(void *param)
{
	ft_free_all(param);
	exit(0);
}

int	ft_mouse(int buttom, int x, int y, t_mlx *param)
{
	(void)x;
	(void)y;
	fflush(stdout);
	if (buttom == SCROLL_UP)
		ft_zoom_out(param->limit);
	if (buttom == SCROLL_DOWN)
		ft_zoom(param->limit);
	ft_call(*param);
	return (0);
}

int	ft_key(int keycode, t_mlx *param)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(param->mlx, param->windw);
		ft_free_all(param);
		exit(0);
	}
	return (0);
}

void	ft_my_put_pixel_colors(t_data *img, int x, int y, int colors)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pix / 8));
	*(unsigned int *)dst = colors;
}

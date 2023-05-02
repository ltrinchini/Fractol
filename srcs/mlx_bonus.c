/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:27:23 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/03/07 10:11:17 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol_bonus.h"

int	ft_close(void *param)
{
	ft_free_all(param);
	exit(0);
}

int	ft_mouse(int buttom, int x, int y, t_mlx *param)
{
	fflush(stdout);
	if (buttom == SCROLL_UP)
		ft_zoom_out(param->limit);
	if (buttom == SCROLL_DOWN)
		ft_zoom(param->limit, x, y);
	ft_call(*param);
	return (0);
}

static void	ft_key_help(int keycode, t_mlx *param)
{
	if (keycode == ONE_KEYPAD || keycode == ONE)
		*param->flag_color = 1;
	if (keycode == TWO_KEYPAD || keycode == TWO)
		*param->flag_color = 2;
	if (keycode == THREE_KEYPAD || keycode == THREE)
		*param->flag_color = 3;
	if (keycode == FOUR_KEYPAD || keycode == FOUR)
		*param->flag_color = 4;
	if (keycode == ESC)
	{
		mlx_destroy_window(param->mlx, param->windw);
		ft_free_all(param);
		exit(0);
	}
}

int	ft_key(int keycode, t_mlx *param)
{
	if (keycode == LETTER_R)
		ft_init_limit(*param);
	if (keycode == ADD_KEYPAD || keycode == ADD)
		(*(param->precision))+= 10;
	if (keycode == LESS_KEYPAD || keycode == LESS)
	{
		if (*(param->precision) > 1)
			(*(param->precision))--;
	}
	if (keycode == LEFT)
		ft_move_left(param->limit);
	if (keycode == RIGHT)
		ft_move_right(param->limit);
	if (keycode == UP)
		ft_move_up(param->limit);
	if (keycode == DOWN)
		ft_move_down(param->limit);
	if (keycode == SPACE)
		*param->mouse *= -1;
	ft_key_help(keycode, param);
	ft_call(*param);
	return (0);
}

void	ft_my_put_pixel_colors(t_data *img, int x, int y, int colors)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pix / 8));
	*(unsigned int *)dst = colors;
}

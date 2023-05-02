/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:11:06 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/25 10:44:26 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol.h"

static int	ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

static t_vec	ft_palette(float t, t_vec4 param_c)
{
	t_vec	dst;

	dst.r = param_c.a.r + param_c.b.r
		* cos(6.28 * (param_c.c.r * t + param_c.d.r));
	dst.g = param_c.a.g + param_c.b.g
		* cos(6.28 * (param_c.c.g * t + param_c.d.g));
	dst.b = param_c.a.b + param_c.b.b
		* cos(6.28 * (param_c.c.b * t + param_c.d.b));
	return (dst);
}

static void	ft_chosen_color(t_vec4 *param_c, int choice)
{
	if (choice == 1)
		ft_init_color_one(param_c);
	if (choice == 2)
		ft_init_color_two(param_c);
	if (choice == 3)
		ft_init_color_three(param_c);
	if (choice == 4)
		ft_init_color_four(param_c);
}

void	ft_draw(t_mlx mlx, t_coord img, unsigned int i)
{
	double	var;
	t_vec	dst;
	t_vec4	param_c;

	ft_chosen_color(&param_c, *mlx.flag_color);
	var = 1.0 / (float)*mlx.precision;
	if (i < *mlx.precision)
	{
		dst = ft_palette(i * var, param_c);
		ft_my_put_pixel_colors(mlx.img, img.x, img.y,
			ft_rgb(dst.r * 255, dst.g * 255, dst.b * 255));
	}
	else
		ft_my_put_pixel_colors(mlx.img, img.x, img.y, 0);
}

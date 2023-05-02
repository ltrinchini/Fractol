/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:36:57 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/28 08:40:39 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol.h"

static	void	ft_txt(void)
{
	ft_putstr_fd("=============FRACTOl============\n", 1);
	ft_putstr_fd("ESC: Exit\n", 1);
	ft_putstr_fd("mouse wheel: zoom / zoom out\n", 1);
	ft_putstr_fd("================================\n", 1);
}

void	ft_call(t_mlx mlx)
{
	if (*mlx.flag == MANDELBROT)
	{
		ft_call_mandelbrot(mlx);
	}
	if (*mlx.flag == JULIA)
	{
		ft_call_julia(mlx, mlx.c->r, mlx.c->i);
	}
	mlx_put_image_to_window(mlx.mlx, mlx.windw, mlx.img->img, 0, 0);
}

static int	ft_mouse_move(int x, int y, t_mlx *param)
{
	if (*param->flag == JULIA && *param->mouse == ON)
	{
		if (x > 0 && y >= 0 && x <= WIDTH_WINDOW && y <= HEIGHT_WINDOW)
		{
			param->c->r = 2.7 / (float)WIDTH_WINDOW * x - 2.1;
			param->c->i = 2.4 / (float)HEIGHT_WINDOW * y - 1.2;
			ft_call_julia(*param, param->c->r, param->c->i);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = ft_init_mlx();
	*mlx->flag = ft_flag(ac, av);
	mlx->mlx = mlx_init();
	mlx->windw = mlx_new_window(mlx->mlx, WIDTH_WINDOW, HEIGHT_WINDOW, "42");
	mlx->img->img = mlx_new_image(mlx->mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img,
			&mlx->img->bits_per_pix, &mlx->img->size_line, &mlx->img->endian);
	*mlx->flag_color = 1;
	if (*mlx->flag == JULIA)
		ft_start_init_julia(mlx, av);
	ft_init_limit(*mlx);
	ft_txt();
	ft_call(*mlx);
	mlx_key_hook(mlx->windw, &ft_key, mlx);
	mlx_mouse_hook(mlx->windw, &ft_mouse, mlx);
	mlx_hook(mlx->windw, 17, 1L << 3, &ft_close, mlx);
	mlx_hook(mlx->windw, 6, 1L << 6, &ft_mouse_move, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->windw, mlx->img->img, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}

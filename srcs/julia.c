/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:46:12 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/03/07 10:39:22 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol.h"

void	ft_start_init_julia(t_mlx *param, char **av)
{
	param->c->r = ft_atof(av[2]);
	param->c->i = ft_atof(av[3]);
	param->c->i *= -1;
}

void	ft_check_arg_julia(char **av)
{
	int	i;
	int	j;

	i = 2;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isnum(av[i][j]) && av[i][j] != '.')
			{
				if (j == 0 && av[i][j] != '-')
					ft_error_msg_usage();
			}
			j++;
		}
		i++;
	}
}

static	t_scale	ft_scale(t_limit lim)
{
	t_scale	scale;

	scale.x = WIDTH_WINDOW / (lim.x_max - lim.x_min);
	scale.y = HEIGHT_WINDOW / (lim.y_max - lim.y_min);
	return (scale);
}

static int	ft_julia(t_coord img, t_scale scale, t_mlx mlx, t_nb_cmplx start)
{
	t_nb_cmplx		c;
	t_nb_cmplx		z;
	double			temp;
	unsigned int	i;

	c.r = start.r;
	c.i = start.i;
	z.r = img.x / scale.x + mlx.limit->x_min;
	z.i = img.y / scale.y + mlx.limit->y_min;
	i = 1;
	while (((z.r * z.r + z.i * z.i) < 4) && (i < *mlx.precision))
	{
		temp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * temp + c.i;
		i++;
	}
	ft_draw(mlx, img, i);
	return (0);
}

int	ft_call_julia(t_mlx mlx, float r, float i)
{
	t_coord		img;
	t_nb_cmplx	start;

	start.r = r;
	start.i = i;
	img.x = 0;
	while (img.x < WIDTH_WINDOW)
	{
		img.y = 0;
		while (img.y < HEIGHT_WINDOW)
		{
			ft_julia(img, ft_scale(*mlx.limit), mlx, start);
			img.y++;
		}
		img.x++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.windw, mlx.img->img, 0, 0);
	return (0);
}

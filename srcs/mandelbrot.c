/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:22:32 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/02 11:51:03 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol.h"

static t_scale	ft_scale(t_limit lim)
{
	t_scale	scale;

	scale.x = WIDTH_WINDOW / (lim.x_max - lim.x_min);
	scale.y = HEIGHT_WINDOW / (lim.y_max - lim.y_min);
	return (scale);
}

static int	ft_mandelbrot(t_coord img, t_scale scale, t_mlx mlx)
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
		z.i = 2 * z.i * temp + c.i;
		i++;
	}
	ft_draw(mlx, img, i);
	return (0);
}

static void	*ft_thread(void *ptr)
{
	t_mlx mlx;
	t_coord	img;
	int		start_y;
	int		end_x;
	int		end_y;
	
	mlx = *(t_mlx *)ptr;
	if (ptr)
		free(ptr);
	img.x = mlx.start_x;
	start_y = mlx.start_y;
	end_x = mlx.end_x;
	end_y = mlx.end_y;
	while (img.x < end_x)
	{
		img.y = start_y;
		while (img.y < end_y)
		{
			ft_mandelbrot(img, ft_scale(*mlx.limit), mlx);
			img.y++;
		}
		img.x++;
	}
	return (NULL);
}

int ft_call_mandelbrot(t_mlx mlx)
{
	pthread_t id[11];
	t_mlx *ptr;
	int i;

	i = 0;
	mlx.start_y = 0;
	mlx.end_y = HEIGHT_WINDOW;
	mlx.start_x = 0;

	while (i < 10)
	{
		ptr = malloc(sizeof(t_mlx));
		mlx.end_x = (WIDTH_WINDOW / 9) * i;
		*ptr = mlx;
		pthread_create(&id[i], NULL, ft_thread, (void *)ptr);
		mlx.start_x = mlx.end_x;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(id[i], NULL);
		i++;
	}
	return (0);
}

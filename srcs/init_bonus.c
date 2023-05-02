/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:43:38 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/02 11:52:40 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol_bonus.h"

t_mlx	*ft_init_mlx(void)
{
	t_mlx	*dst;

	dst = malloc(sizeof(t_mlx));
	if (!dst)
	{
		perror("Fractol");
		exit(0);
	}
	dst->img = malloc(sizeof(t_data));
	dst->precision = malloc(sizeof(int));
	dst->flag = malloc(sizeof(int));
	dst->limit = malloc(sizeof(t_limit));
	dst->mouse = malloc(sizeof(int));
	dst->c = malloc(sizeof(t_nb_cmplx));
	dst->flag_color = malloc(sizeof(int));
	if (!dst->img || !dst->precision || !dst->flag || !dst->limit
		|| !dst->mouse || !dst->c || !dst->flag_color)
	{
		ft_free_all(dst);
		perror("Fractol");
		exit(0);
	}
	return (dst);
}

void	ft_init_limit(t_mlx mlx)
{
	if (*mlx.flag == MANDELBROT || *mlx.flag == TRICORN || *mlx.flag == BSHIP)
	{
		mlx.limit->x_min = -2.5;
		mlx.limit->x_max = 1.1;
		mlx.limit->y_min = -1.7;
		mlx.limit->y_max = 1.7;
		*mlx.precision = PRECISION_START_MANDELBROT;
		*mlx.mouse = OFF;
	}
	if (*mlx.flag == JULIA)
	{
		mlx.limit->x_min = -1.5;
		mlx.limit->x_max = 1.5;
		mlx.limit->y_min = -1.2;
		mlx.limit->y_max = 1.2;
		*mlx.precision = PRECISION_START_JULIA;
		*mlx.mouse = OFF;
	}
}

int	ft_flag(int ac, char **av)
{
	if (ac == 1 || ac > 5)
		ft_error_msg_usage();
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			return (MANDELBROT);
		if (!ft_strcmp(av[1], "tricorn"))
			return (TRICORN);
		if (!ft_strcmp(av[1], "burningship"))
			return (BSHIP);
	}
	if (ac == 4)
	{
		if (!ft_strcmp(av[1], "julia"))
		{
			ft_check_arg_julia(av);
			return (JULIA);
		}
	}
	ft_error_msg_usage();
	return (0);
}

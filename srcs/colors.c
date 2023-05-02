/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:52:29 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/24 11:01:41 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol.h"

void	ft_init_color_one(t_vec4 *param_c)
{	
	param_c->a.r = 0.5;
	param_c->a.g = 0.5;
	param_c->a.b = 0.5;
	param_c->b.r = 0.5;
	param_c->b.g = 0.5;
	param_c->b.b = 0.5;
	param_c->c.r = 1;
	param_c->c.g = 1;
	param_c->c.b = 1;
	param_c->d.r = 0;
	param_c->d.g = 0.33;
	param_c->d.b = 0.67;
}

void	ft_init_color_two(t_vec4 *param_c)
{
	param_c->a.r = 0.8;
	param_c->a.g = 0.5;
	param_c->a.b = 0.4;
	param_c->b.r = 0.2;
	param_c->b.g = 0.4;
	param_c->b.b = 0.2;
	param_c->c.r = 2;
	param_c->c.g = 1;
	param_c->c.b = 1;
	param_c->d.r = 0;
	param_c->d.g = 0.25;
	param_c->d.b = 0.25;
}

void	ft_init_color_three(t_vec4 *param_c)
{
	param_c->a.r = 0.5;
	param_c->a.g = 0.5;
	param_c->a.b = 0.5;
	param_c->b.r = 0.5;
	param_c->b.g = 0.5;
	param_c->b.b = 0.5;
	param_c->c.r = 1;
	param_c->c.g = 1;
	param_c->c.b = 1;
	param_c->d.r = 0.3;
	param_c->d.g = 0.2;
	param_c->d.b = 0.2;
}

void	ft_init_color_four(t_vec4 *param_c)
{
	param_c->a.r = 0.5;
	param_c->a.g = 0.5;
	param_c->a.b = 0.5;
	param_c->b.r = 0.5;
	param_c->b.g = 0.5;
	param_c->b.b = 0.5;
	param_c->c.r = 2;
	param_c->c.g = 1;
	param_c->c.b = 0;
	param_c->d.r = 0.5;
	param_c->d.g = 0.2;
	param_c->d.b = 0.25;
}

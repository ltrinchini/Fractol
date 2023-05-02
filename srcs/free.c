/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:16:32 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/25 15:59:27 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol.h"

void	ft_free_all(t_mlx *ptr)
{
	if (ptr->img)
		free(ptr->img);
	if (ptr->precision)
		free(ptr->precision);
	if (ptr->flag)
		free(ptr->flag);
	if (ptr->limit)
		free(ptr->limit);
	if (ptr->mouse)
		free(ptr->mouse);
	if (ptr->c)
		free(ptr->c);
	if (ptr->flag_color)
		free(ptr->flag_color);
	if (ptr)
		free(ptr);
}

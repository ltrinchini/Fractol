/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:36:43 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/25 23:03:41 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/fractol_bonus.h"

void	ft_error_msg_usage(void)
{
	char	*str1;
	char	*str2;	
	char	*str3;
	char	*str4;

	str1 = "Error: Usage of fractol \"./fractol target_name\"\n";
	str2 = "Target_name: mandelbrot | julia | tricorn | burningship\n";
	str3 = "Julia use \"./fractol julia nb_reel nb_imag\"\n";
	str4 = "Ex: ./julia 0.3 -0.5\n";
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	ft_putstr_fd(str4, 2);
	exit(0);
}

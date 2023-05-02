/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:18:54 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/03/07 10:33:48 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/srcs/libft.h"
# include "../minilibx/mlx.h"

//Fractal 
# define MANDELBROT 0
# define JULIA 1
# define TRICORN 2
# define BSHIP 3

//Config
# define WIDTH_WINDOW 540
# define HEIGHT_WINDOW 480
# define PRECISION_START_MANDELBROT 200
# define PRECISION_START_JULIA 150
# define SPEED_MOVE 0.15
# define SPEED_ZOOM 0.1
# define ON 1
# define OFF -1
# define EPSILON 1e-14
# define DELTA 1e-17

//Mouse
# define SCROLL_UP 4
# define SCROLL_DOWN 5

//Keyboard
# define ESC 53
# define ADD_KEYPAD 69
# define LESS_KEYPAD 78
# define ADD 24
# define LESS 27
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define SPACE 49
# define ONE_KEYPAD 83
# define TWO_KEYPAD 84
# define THREE_KEYPAD 85
# define FOUR_KEYPAD 86
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define LETTER_R 15

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pix;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_nb_cmplx
{
	double	r;
	double	i;
}	t_nb_cmplx;

typedef struct s_limit
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_limit;

typedef struct s_scale
{
	double	x;
	double	y;
}	t_scale;

typedef struct s_mlx
{
	void			*mlx;
	void			*windw;
	t_data			*img;
	unsigned int	*precision;
	t_limit			*limit;
	unsigned int	*flag;
	unsigned int	*mouse;
	unsigned int	*flag_color;
	t_nb_cmplx		*c;
}	t_mlx;

typedef struct s_vec
{
	double	r;
	double	g;
	double	b;
}	t_vec;

typedef struct s_vec4
{
	t_vec	a;
	t_vec	b;
	t_vec	c;
	t_vec	d;
}	t_vec4;

//Functions mlx
void	ft_my_put_pixel_colors(t_data *img, int x, int y, int colors);
int		ft_key(int keycode, t_mlx *param);
int		ft_close(void *param);

//Functions fractol
int		ft_call_mandelbrot(t_mlx mlx);
int		ft_call_julia(t_mlx mlx, float r, float i);
int		ft_call_tricorn(t_mlx mlx);
int		ft_call_burningship(t_mlx mlx);
void	ft_init_limit(t_mlx mlx);
void	ft_call(t_mlx mlx);

//Functions events
int		ft_mouse(int buttom, int x, int y, t_mlx *param);

//Functions draw
void	ft_draw(t_mlx mlx, t_coord img, unsigned int i);

//Functions color
void	ft_init_color_one(t_vec4 *param_c);
void	ft_init_color_two(t_vec4 *param_c);
void	ft_init_color_three(t_vec4 *param_c);
void	ft_init_color_four(t_vec4 *param_c);

//Functions move & zoom
void	ft_move_right(t_limit *limit);
void	ft_move_left(t_limit *limit);
void	ft_move_up(t_limit *limit);
void	ft_move_down(t_limit *limit);
void	ft_zoom(t_limit *limite, int x, int y);
void	ft_zoom_out(t_limit *limite);

//Functions manag error
void	ft_error_msg_usage(void);
void	ft_check_arg_julia(char **av);

//Functions init
t_mlx	*ft_init_mlx(void);
void	ft_init_limit(t_mlx mlx);
int		ft_flag(int ac, char **av);
void	ft_start_init_julia(t_mlx *param, char **av);

//Tools functions
void	ft_free_all(t_mlx *ptr);
#endif

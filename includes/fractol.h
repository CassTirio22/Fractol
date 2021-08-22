/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:33:30 by ctirions          #+#    #+#             */
/*   Updated: 2021/08/22 18:03:07 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# define THREADS 320
# define WIDTH 320
# define HEIGHT 320

# define EXIT 53
# define ZOOM 126
# define UNZOOM 125
# define LEFT 2
# define RIGHT 0
# define UP 1
# define DOWN 13 

typedef struct s_var	t_var;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	long double	x1;
	long double	x_size;
	long double	y1;
	long double	y_size;
	long double	zoom;
	long double	max_iter;
	int			id;
	int			color;
	int			go_up;
	int			go_down;
	int			go_left;
	int			go_right;
	int			mouse[2];
}				t_data;

typedef struct s_thread
{
	int		id;
	t_var	*vars;
}				t_thread;

typedef struct s_render
{
	pthread_t	threads[THREADS];
	t_thread	args[THREADS];
}				t_render;

struct s_var
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		*data;
	t_img		*img;
	t_render	render;
	int			id;
};

/*------DISPLAY------*/

void	ft_reset(t_var *vars);
void	pixel_put(t_img *img, int x, int y, int color);
void	usage_msg(void);
void	mandelbrot(t_var *vars, int x, int y);
void	julia(t_var *vars, int x, int y);
void	burningship(t_var *vars, int x, int y);

/*------INIT------*/

void	init_struct(t_var *vars);
void	init_var(t_var *vars);
void	init_mlx(t_var *vars);
void	init_julia(t_data *data);
void	init_mandelbrot(t_data *data);
void	init_burningship(t_data *data);

/*------MOVE------*/

int		move(t_var *vars);
void	zoom(t_var *vars);
void	unzoom(t_var *vars);

/*------THREADS-------*/

void	*use_threads(void *v);
int		init_threads(t_var *vars);

/*------HOOK------*/

int		mouse_pos(int x, int y, t_var *vars);
int		key_press(int keycode, t_var *vars);
int		key_release(int keycode, t_var *vars);
int		mouse_wheel(int button, int x, int y, t_var *vars);
int		draw_fract(t_var *vars, int x, int y);

/*------UTILS------*/

void	ft_close(void);
void	ft_croix(t_var *vars);
int		color(int color, int i);
int		ft_strcmp(const char *s1, const char *s2);

#endif
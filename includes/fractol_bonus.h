/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:33:30 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/08 17:27:52 by ctirions         ###   ########.fr       */
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

# define THREADS 4
# define WIDTH 700
# define HEIGHT 640

# define EXIT 53
# define ZOOM 126
# define UNZOOM 125
# define LEFT 2
# define RIGHT 0
# define UP 1
# define DOWN 13 

typedef struct  s_var   t_var;

typedef struct  s_img
{
    void    *img;
    char    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}               t_img;

typedef struct  s_data
{
    long double  x1;
    long double  x_size;
    long double  y1;
    long double  y_size;
    long double  zoom;
    long double  max_iter;
    int id;
    int go_up;
    int go_down;
    int go_left;
    int go_right;
}               t_data;

typedef struct			s_thread
{
	int					id;
	t_var				*vars;
}						t_thread;

typedef struct  s_render
{
	pthread_t   threads[THREADS];
	t_thread    args[THREADS];
}				t_render;

struct  s_var
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  *data;
    t_img   *img;
    t_render    render;
    int id;
    int cord[2];
};

/*------DISPLAY------*/

void    ft_reset(t_var *vars);
void	pixel_put(t_img *img, int x, int y, int color);
void    usage_msg(void);
void    mandelbrot(t_var *vars);
void    julia(t_var *vars);
void    burningship(t_var *vars);

/*------INIT------*/

void    init_struct(t_var *vars);
void    init_var(t_var *vars);
void    init_mlx(t_var *vars);
void    init_julia(t_data *data);
void    init_mandelbrot(t_data *data);
void    init_burningship(t_data *data);

/*------MOVE------*/

void    zoom(t_var *vars);
void    unzoom(t_var *vars);

/*------THREADS-------*/

void    *use_threads(void *v);
void    init_threads(t_var *vars);

/*------HOOK------*/

int key_press(int keycode, t_var *vars);
int key_release(int keycode, t_var *vars);
int mouse_wheel(int button, int x, int y, t_var *vars);
int draw_fract(t_var *vars);

/*------COLORS------*/

int color1(int i);
int color2(int i);

/*------UTILS------*/

void    ft_close(void);
void	ft_croix(t_var *vars);
int	ft_strcmp(const char *s1, const char *s2);

#endif
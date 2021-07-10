/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:33:30 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/10 15:42:06 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define EXIT 53
# define ZOOM 126
# define UNZOOM 125


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
    int screen[2];
}               t_data;

typedef struct  s_var
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  *data;
    t_img   *img;
}              t_var;

/*------DISPLAY------*/

void    ft_reset(t_var *vars);
void	pixel_put(t_img *img, int x, int y, int color);
void    mandelbrot(t_var *vars);
void    julia(t_var *vars);

/*------INIT------*/

void    init_var(t_var *vars, int argc, char **argv);
void    init_mlx(t_var *vars);
void    init_julia(t_data *data);
void    init_mandelbrot(t_data *data);

/*------MOVE------*/

void    zoom(t_var *vars);
void    unzoom(t_var *vars);

/*------HOOK------*/

int close_window(t_var *vars);
int key_hook(int keycode, t_var *vars);
int mouse_wheel(int button, int x, int y, t_var *vars);
int draw_fract(t_var *vars);

/*------UTILS------*/

void	ft_croix(t_var *vars);
void    error(int argc, char **argv, t_var *vars);
int	ft_strcmp(const char *s1, const char *s2);

#endif
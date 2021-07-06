/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:43:12 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/06 17:13:42 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void    init_var(t_var *vars, int argc, char **argv)
{
    vars->img = malloc(sizeof(t_img));
    vars->data = malloc(sizeof(t_data));
    error(argc, argv, vars);
    if (vars->data->id == 0)
        init_mandelbrot(vars->data);
    else if (vars->data->id == 1)
        init_julia(vars->data);
    vars->data->zoom = 0;
    vars->data->go_up = 0;
    vars->data->go_down = 0;
    vars->data->go_left = 0;
    vars->data->go_right = 0;
    vars->data->max_iter = 200;
    init_mlx(vars);
}

void    init_mlx(t_var *vars)
{
    vars->mlx_ptr = mlx_init();
    vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->data->screen[0], \
    vars->data->screen[1], "FRACTOL");
    vars->img->img = mlx_new_image(vars->mlx_ptr, vars->data->screen[0], \
    vars->data->screen[1]);
    vars->img->addr = mlx_get_data_addr(vars->img->img, \
    &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
    mlx_hook(vars->win_ptr, 2, 1L << 0, key_press, vars);
    mlx_hook(vars->win_ptr, 3, 1L << 1, key_release, vars);
    mlx_hook(vars->win_ptr, 4, 1L << 2 , mouse_wheel, vars);
    mlx_loop_hook(vars->mlx_ptr, draw_fract, vars);
    mlx_loop(vars->mlx_ptr);
}

void    init_julia(t_data *data)
{
    data->x1 = -2;
    data->x_size = 4;
    data->y1 = -1;
    data->y_size = 3;
    data->screen[0] = 600;
    data->screen[1] = 800;
}

void    init_mandelbrot(t_data *data)
{
    data->x1 = -2;
    data->x_size = 2.7;
    data->y1 = -1.2;
    data->y_size = 2.4;
    data->screen[0] = 500;
    data->screen[1] = 440;
}
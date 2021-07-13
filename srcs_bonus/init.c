/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:43:12 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/13 18:17:02 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void    init_struct(t_var *vars)
{
    vars->img = malloc(sizeof(t_img));
    vars->data = malloc(sizeof(t_data));
}

void    init_var(t_var *vars)
{
    if (vars->id == 0)
        init_mandelbrot(vars->data);
    else if (vars->id == 1)
        init_julia(vars->data);
    else if (vars->id == 2)
        init_burningship(vars->data);
    vars->data->zoom = 0;
    vars->data->go_up = 0;
    vars->data->go_down = 0;
    vars->data->go_left = 0;
    vars->data->go_right = 0;
    vars->data->max_iter = 200;
}

void    init_mlx(t_var *vars)
{
    vars->mlx_ptr = mlx_init();
    vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIDTH, \
    HEIGHT, "FRACTOL");
    vars->img->img = mlx_new_image(vars->mlx_ptr, WIDTH, HEIGHT);
    vars->img->addr = mlx_get_data_addr(vars->img->img, \
    &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
    mlx_hook(vars->win_ptr, 2, 1L << 0, key_press, vars);
    mlx_hook(vars->win_ptr, 3, 1L << 1, key_release, vars);
    mlx_hook(vars->win_ptr, 4, 1L << 2 , mouse_wheel, vars);
    //mlx_loop_hook(vars->mlx_ptr, draw_fract, vars);
}
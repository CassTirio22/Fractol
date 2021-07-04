/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:05:41 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/04 18:54:22 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int key_hook(int keycode, t_var *vars)
{
    if (keycode == EXIT)
        exit(1);
    else if (keycode == ZOOM)
        zoom(vars);
    else if (keycode == UNZOOM)
        unzoom(vars);
    else if (keycode == LEFT)
        vars->data->x1 += vars->data->x_size / 20;
    else if (keycode == RIGHT)
        vars->data->x1 -= vars->data->x_size / 20;
    else if (keycode == UP)
        vars->data->y1 += vars->data->y_size / 20;
    else if (keycode == DOWN)
        vars->data->y1 -= vars->data->y_size / 20;
    ft_reset(vars);
    return (0);
}

int mouse_wheel(int button, int x, int y, t_var *vars)
{
    x = 6;
    y = 9;
    if (button == 4)
        vars->data->zoom = 1;
    else if (button == 5)
        vars->data->zoom = -1;
    return (0);
}

int move(t_var *vars)
{
    if (vars->data->zoom == 1)
        zoom(vars);
    else if (vars->data->zoom == -1)
        unzoom(vars);
    return (1);
}

int draw_fract(t_var *vars)
{
    if (move(vars))
    {
        ft_reset(vars);
        if (vars->data->id == 0)
            mandelbrot(vars);
	    else if (vars->data->id == 1)
		    julia(vars);
        ft_croix(vars);
        mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
    }
    return (0);
}
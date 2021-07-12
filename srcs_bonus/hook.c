/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:05:41 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/12 16:29:39 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int key_press(int keycode, t_var *vars)
{
    if (keycode == EXIT)
        ft_close();
    else if (keycode == ZOOM)
        zoom(vars);
    else if (keycode == UNZOOM)
        unzoom(vars);
    else if (keycode == LEFT)
         vars->data->go_left = 1;
    else if (keycode == RIGHT)
        vars->data->go_right = 1;
    else if (keycode == UP)
        vars->data->go_up = 1;
    else if (keycode == DOWN)
        vars->data->go_down = 1;
    return (0);
}

int key_release(int keycode, t_var *vars)
{
    if (keycode == EXIT)
        ft_close();
    else if (keycode == LEFT)
         vars->data->go_left = 0;
    else if (keycode == RIGHT)
        vars->data->go_right = 0;
    else if (keycode == UP)
        vars->data->go_up = 0;
    else if (keycode == DOWN)
        vars->data->go_down = 0;
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

static int move(t_var *vars)
{
    if (vars->data->zoom == 1)
        zoom(vars);
    else if (vars->data->zoom == -1)
        unzoom(vars);
    if (vars->data->go_up)
        vars->data->y1 += vars->data->y_size / 30;
    else if (vars->data->go_down)
        vars->data->y1 -= vars->data->y_size / 30;
    else if (vars->data->go_left)
        vars->data->x1 += vars->data->x_size / 30;
    else if (vars->data->go_right)
        vars->data->x1 -= vars->data->x_size / 30;
    vars->data->zoom = 0;
    ft_reset(vars);
    return (1);
}

int draw_fract(t_var *vars, int x, int y)
{
    if (move(vars))
    {
        if (vars->id == 0)
            mandelbrot(vars, x, y);
	    else if (vars->id == 1)
		    julia(vars, x, y);
        else if (vars->id == 2)
		    burningship(vars, x, y);
       // ft_croix(vars);
    }
    mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
    return (0);
}
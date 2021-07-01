/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:01:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/01 18:04:45 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static  void    zoom(t_var *vars)
{
    vars->data->zoom *= 1.1;
    vars->data->y1 += 0.9 / vars->data->zoom * 20;
    vars->data->x1 += 1.1 / vars->data->zoom * 20;
}

static  void    unzoom(t_var *vars)
{
    vars->data->zoom *= 0.9;
    vars->data->y1 -= 0.9 / vars->data->zoom * 20;
    vars->data->x1 -= 1.1 / vars->data->zoom * 20;
}

int key_hook(int keycode, t_var *vars)
{
    if (keycode == EXIT)
        exit(1);
    else if (keycode == ZOOM)
        zoom(vars);
    else if (keycode == UNZOOM)
        unzoom(vars);
    else if (keycode == LEFT)
        vars->data->x1 += 1 / vars->data->zoom * 20;
    else if (keycode == RIGHT)
        vars->data->x1 -= 1 / vars->data->zoom * 20;
    else if (keycode == UP)
        vars->data->y1 += 1 / vars->data->zoom * 20;
    else if (keycode == DOWN)
        vars->data->y1 -= 1 / vars->data->zoom * 20;
    ft_reset(vars);
    draw_fract(vars);
    mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:01:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/06/25 20:21:30 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int key_hook(int keycode, t_var *vars)
{
    printf("%d\n", keycode);
    if (keycode == EXIT)
        exit(1);
    else if (keycode == ZOOM)
        vars->data->zoom *= 1.1;
    else if (keycode == UNZOOM)
        vars->data->zoom *= 0.9;
    else if (keycode == LEFT)
        vars->data->x1 += 0.005;
    else if (keycode == RIGHT)
        vars->data->x1 -= 0.005;
    else if (keycode == UP)
        vars->data->y1 += 0.005;
    else if (keycode == DOWN)
        vars->data->y1 -= 0.005;
    ft_reset(vars);
    mandelbrot(vars);
    mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
    return (0);
}
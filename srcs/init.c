/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:43:12 by ctirions          #+#    #+#             */
/*   Updated: 2021/06/25 19:44:12 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void    init_var(t_var *vars)
{
    vars->img = malloc(sizeof(t_img));
    vars->data = malloc(sizeof(t_data));
    vars->mlx_ptr = mlx_init();
    vars->win_ptr = mlx_new_window(vars->mlx_ptr, 270, 240, "FRACTOL");
    vars->img->img = mlx_new_image(vars->mlx_ptr, 270, 240);
    vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
    init_data(vars->data);
}

void    init_data(t_data *data)
{
    data->x1 = -2.1;
    data->x2 = 0.6;
    data->y1 = -1.2;
    data->y2 = 1.2;
    data->zoom = 100;
    data->max_iter = 50;
}
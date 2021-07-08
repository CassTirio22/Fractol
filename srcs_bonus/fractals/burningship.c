/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:20:23 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/08 17:15:08 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

void    init_burningship(t_data *data)
{
    data->x1 = -2;
    data->x_size = 2.7;
    data->y1 = -1.2;
    data->y_size = 2.4;
}

void    burningship(t_var *vars)
{
    long double c[2];
    long double z[2];
    long double zoom[2];
    long double tmp;
    int i;

    zoom[0] = vars->data->x_size / WIDTH;
    zoom[1] = vars->data->y_size / HEIGHT;
    c[0] = vars->cord[0] * zoom[0] + vars->data->x1;
    c[1] = vars->cord[1] * zoom[1] + vars->data->y1;
    z[0] = 0;
    z[1] = 0;
    i = -1;
    while (z[0] * z[0] + z[1] * z[1] < 4 && ++i < vars->data->max_iter)
    {
        tmp = z[0] * z[0] - z[1] * z[1];
        z[1] = fabsl(2 * z[0] * z[1] + c[1]);
        z[0] = fabsl(tmp + c[0]);
    }
    if (i != vars->data->max_iter)
        pixel_put(vars->img, vars->cord[0], vars->cord[1], color2(i));
}
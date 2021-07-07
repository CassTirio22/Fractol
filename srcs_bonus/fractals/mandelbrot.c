/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:21:28 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/07 18:22:15 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

void    mandelbrot(t_var *vars)
{
    long double  c[2];
    long double  z[2];
    long double  zoom[2];
    long double  tmp;
    int cord[2];
    int i;

    cord[0] = -1;
    zoom[0] = vars->data->x_size / vars->data->screen[0];
    zoom[1] = vars->data->y_size / vars->data->screen[1];
    while (++cord[0] < vars->data->screen[0])
    {
        cord[1] = -1;
        while (++cord[1] < vars->data->screen[1])
        {
            c[0] = cord[0] * zoom[0] + vars->data->x1;
            c[1] = cord[1] * zoom[1] + vars->data->y1;
            z[0] = 0;
            z[1] = 0;
            i = -1;
            while (z[0] * z[0] + z[1] * z[1] < 4 && ++i < vars->data->max_iter)
            {
                tmp = z[0];
                z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
                z[1] = 2 * z[1] * tmp + c[1];
            }
            if (i != vars->data->max_iter)
                pixel_put(vars->img, cord[0], cord[1], color1(i));
        }
    }
}
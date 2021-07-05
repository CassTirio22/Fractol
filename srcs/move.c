/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:01:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/05 16:07:22 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void    zoom(t_var *vars)
{
    vars->data->x1 += vars->data->x_size * 0.05;
    vars->data->y1 += vars->data->y_size * 0.05;
    vars->data->x_size *= 0.9;
    vars->data->y_size *= 0.9;
}

void    unzoom(t_var *vars)
{
    vars->data->x1 -= vars->data->x_size * 0.05;
    vars->data->y1 -= vars->data->y_size * 0.05;
    vars->data->x_size *= 1.1;
    vars->data->y_size *= 1.1;
}
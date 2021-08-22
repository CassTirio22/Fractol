/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:20:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/08/22 17:53:44 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	init_julia(t_data *data)
{
	data->x1 = -1;
	data->x_size = 2;
	data->y1 = -1;
	data->y_size = 1.5;
	data->color = 3;
}

void	julia(t_var *vars, int x, int y)
{
	long double	c[2];
	long double	z[2];
	long double	zoom[2];
	long double	tmp;
	int			i;

	zoom[0] = vars->data->x_size / WIDTH;
	zoom[1] = vars->data->y_size / HEIGHT;
	c[0] = (float)(4 * vars->data->mouse[0]) / WIDTH - 2;
	c[1] = (float)(4 * vars->data->mouse[1]) / HEIGHT - 2;
	z[0] = x * zoom[0] + vars->data->x1;
	z[1] = y * zoom[1] + vars->data->y1;
	i = -1;
	while (z[0] * z[0] + z[1] * z[1] < 9000000000 && ++i < vars->data->max_iter)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp + c[1];
	}
	if (i != vars->data->max_iter)
		pixel_put(vars->img, x, y, color(vars->data->color, i));
}

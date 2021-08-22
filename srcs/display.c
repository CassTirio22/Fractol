/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:56:15 by ctirions          #+#    #+#             */
/*   Updated: 2021/08/22 16:29:40 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_var *vars, int x, int y)
{
	long double	c[2];
	long double	z[2];
	long double	zoom[2];
	long double	tmp;
	int			i;

	printf("coucou\n");
	zoom[0] = vars->data->x_size / vars->data->screen[0];
	zoom[1] = vars->data->y_size / vars->data->screen[1];
	c[0] = 0.285;
	c[1] = 0.01;
	z[0] = x * zoom[0] + vars->data->x1;
	z[1] = y * zoom[1] + vars->data->y1;
	i = -1;
	while (z[0] * z[0] + z[1] * z[1] < 4 && ++i < vars->data->max_iter)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp + c[1];
	}
	if (i != vars->data->max_iter)
		pixel_put(vars->img, x, y, 119856 + i * 2500);
}

void	mandelbrot(t_var *vars, int x, int y)
{
	long double	c[2];
	long double	z[2];
	long double	zoom[2];
	long double	tmp;
	int			i;

	zoom[0] = vars->data->x_size / vars->data->screen[0];
	zoom[1] = vars->data->y_size / vars->data->screen[1];
	c[0] = x * zoom[0] + vars->data->x1;
	c[1] = y * zoom[1] + vars->data->y1;
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
		pixel_put(vars->img, x, y, 11931856 + i * 3000);
}

void	ft_reset(t_var *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->data->screen[0])
	{
		j = -1;
		while (++j < vars->data->screen[1])
			pixel_put(vars->img, i, j, 0);
	}
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

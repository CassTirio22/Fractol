/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:05:41 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/25 17:10:49 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	mouse_pos(int x, int y, t_var *vars)
{
	vars->data->mouse[0] = x;
	vars->data->mouse[1] = y;
	init_threads(vars);
	return (0);
}

int	key_press(int keycode, t_var *vars)
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
	else if (keycode == 18)
		vars->data->color = 1;
	else if (keycode == 19)
		vars->data->color = 2;
	else if (keycode == 20)
		vars->data->color = 3;
	else if (keycode == 21)
		vars->data->color = 4;
	init_threads(vars);
	return (0);
}

int	key_release(int keycode, t_var *vars)
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
	init_threads(vars);
	return (0);
}

int	mouse_wheel(int button, int x, int y, t_var *vars)
{
	if (button == 1 || button == 2)
		return (0);
	if (x - WIDTH / 2 < 0)
		vars->data->x1 -= vars->data->x_size * 0.08 * \
		(1 - (float)x / (WIDTH / 2));
	else
		vars->data->x1 += vars->data->x_size * 0.08 * \
		((float)(x - WIDTH / 2) / (WIDTH / 2));
	if (y - HEIGHT / 2 < 0)
		vars->data->y1 -= vars->data->y_size * 0.08 * \
		(1 - (float)y / (HEIGHT / 2));
	else
		vars->data->y1 += vars->data->y_size * 0.08 * \
		((float)(y - HEIGHT / 2) / (HEIGHT / 2));
	if (button == 4)
		vars->data->zoom = 1;
	else if (button == 5)
		vars->data->zoom = -1;
	init_threads(vars);
	return (0);
}

int	draw_fract(t_var *vars, int x, int y)
{
	if (move(vars))
	{
		if (vars->id == 0)
			mandelbrot(vars, x, y);
		else if (vars->id == 1)
			julia(vars, x, y);
		else if (vars->id == 2)
			burningship(vars, x, y);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:05:41 by ctirions          #+#    #+#             */
/*   Updated: 2021/08/22 16:25:16 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_window(t_var *vars)
{
	(void)vars;
	printf("Good bye!\n");
	exit(1);
}

int	key_hook(int keycode, t_var *vars)
{
	if (keycode == EXIT)
		close_window(vars);
	return (0);
}

int	mouse_wheel(int button, int x, int y, t_var *vars)
{
	x = 6;
	y = 9;
	if (button == 4)
		vars->data->zoom = 1;
	else if (button == 5)
		vars->data->zoom = -1;
	return (0);
}

static int	move(t_var *vars)
{
	if (vars->data->zoom == 1)
		zoom(vars);
	else if (vars->data->zoom == -1)
		unzoom(vars);
	vars->data->zoom = 0;
	return (1);
}

int	draw_fract(t_var *vars)
{
	int x;
	int y;

	x = -1;
	while (++x < vars->data->screen[0])
	{
		y = -1;
		while (++y < vars->data->screen[1])
		{
			if (move(vars))
			{
				ft_reset(vars);
				if (vars->data->id == 0)
					mandelbrot(vars, x, y);
				else if (vars->data->id == 1)
					julia(vars, x, y);
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->img->img, 0, 0);
			}
		}
	}
	return (0);
}

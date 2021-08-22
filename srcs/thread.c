/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:56:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/08/22 17:53:53 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*use_threads(void *v)
{
	t_thread	*t;
	int			x;
	int			y;

	t = (t_thread *)v;
	y = HEIGHT / THREADS * t->id - 1;
	while (++y < HEIGHT / THREADS * (t->id + 1))
	{
		x = -1;
		while (++x < WIDTH)
			draw_fract(t->vars, x, y);
	}
	return (NULL);
}

int	init_threads(t_var *vars)
{
	int			i;
	t_render	*r;

	i = -1;
	r = &vars->render;
	ft_reset(vars);
	while (++i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].vars = vars;
		if (pthread_create(r->threads + i, NULL, use_threads, r->args + i))
			ft_close();
	}
	i = -1;
	while (++i < THREADS)
		if (pthread_join(r->threads[i], NULL))
			ft_close();
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:01:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/25 17:05:49 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	zoom(t_var *vars)
{
	vars->data->x1 += vars->data->x_size * 0.05;
	vars->data->y1 += vars->data->y_size * 0.05;
	vars->data->x_size *= 0.9;
	vars->data->y_size *= 0.9;
}

void	unzoom(t_var *vars)
{
	vars->data->x1 -= vars->data->x_size * 0.05;
	vars->data->y1 -= vars->data->y_size * 0.05;
	vars->data->x_size *= 1.1;
	vars->data->y_size *= 1.1;
}

int	move(t_var *vars)
{
	if (vars->data->zoom == 1)
		zoom(vars);
	else if (vars->data->zoom == -1)
		unzoom(vars);
	if (vars->data->go_up)
		vars->data->y1 += vars->data->y_size / 30;
	else if (vars->data->go_down)
		vars->data->y1 -= vars->data->y_size / 30;
	else if (vars->data->go_left)
		vars->data->x1 += vars->data->x_size / 30;
	else if (vars->data->go_right)
		vars->data->x1 -= vars->data->x_size / 30;
	vars->data->go_up = 0;
	vars->data->go_down = 0;
	vars->data->go_left = 0;
	vars->data->go_right = 0;
	vars->data->zoom = 0;
	return (1);
}

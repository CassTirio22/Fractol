/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:35:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/04 18:54:35 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_croix(t_var *vars)
{
	int x;
	int y;
	x = -1;
	y = -1;
	while (++x < vars->data->screen[0])
		pixel_put(vars->img, x, vars->data->screen[1] / 2, 0x3FFAB2);
	while (++y < vars->data->screen[1])
		pixel_put(vars->img, vars->data->screen[0] / 2, y, 0x3FFAB2);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
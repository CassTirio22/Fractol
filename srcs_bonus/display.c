/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:56:15 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/07 17:27:55 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void    ft_reset(t_var *vars)
{
    int i;
    int j;

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
	*(unsigned int*)dst = color;
}
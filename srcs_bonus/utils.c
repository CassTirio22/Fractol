/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:35:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/08 17:25:31 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void    ft_close(void)
{
    write(1, "Good bye\n", 9);
    exit(1);
}

void	ft_croix(t_var *vars)
{
	int x;
	int y;
	x = -1;
	y = -1;
	while (++x < WIDTH)
		pixel_put(vars->img, x, HEIGHT / 2, 0x3FFAB2);
	while (++y < HEIGHT)
		pixel_put(vars->img, WIDTH / 2, y, 0x3FFAB2);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
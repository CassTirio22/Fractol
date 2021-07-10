/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:35:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/10 15:42:06 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void print_error(int error)
{
    if (error == 1)
        printf("Wrong number of arguments!\n");
    else if (error == 2)
    {
        printf("Wrong name for the second argument!\n");
        printf("You have two choice:\n- Mandelbrot\n- Julia\n");
    }
    exit(1);
}

void    error(int argc, char **argv, t_var *vars)
{
    int error;

    vars->data->id = -1;
    error = 0;
    if (argc == 1)
        error = 1;
    if (!error && !ft_strcmp(argv[1], "Mandelbrot"))
        vars->data->id = 0;
    else if (!error && !ft_strcmp(argv[1], "Julia"))
        vars->data->id = 1;
    else if (!error)
        error = 2;
    if (error)
        print_error(error);
}

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
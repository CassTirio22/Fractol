/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:02:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/06/25 20:03:16 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
    t_var   vars;
    init_var(&vars);
    mlx_hook(vars.win_ptr, 2, 1L<<0, &key_hook, &vars);
    mandelbrot(&vars);
    mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, vars.img->img, 0, 0);
    mlx_loop(vars.mlx_ptr);
    return (0);
}

//gcc -lmlx -framework OpenGL -framework AppKit main.c && ./a.out
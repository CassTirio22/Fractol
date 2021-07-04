/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:02:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/04 18:30:13 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    error(int argc, char **argv, t_var *vars)
{
    int error;

    vars->data->id = -1;
    error = 0;
    if (argc != 2)
        error = 1;
    if (!error && !ft_strcmp(argv[1], "Mandelbrot"))
        vars->data->id = 0;
    else if (!error && !ft_strcmp(argv[1], "Julia"))
        vars->data->id = 1;
    else
        error = 1;
    if (error)
    {
        printf("You put a wrong input!\nYou have two different ");
        printf("option:\n\t- Mandelbrot\n\t- Julia\n");
        exit(1);
    }

}

int main(int argc, char **argv)
{
    t_var   vars;
    
    init_var(&vars, argc, argv);
    error(argc, argv, &vars);
    mlx_hook(vars.win_ptr, 2, 1L<<0, key_hook, &vars);
    mlx_hook(vars.win_ptr, 4, 1L << 2 , mouse_wheel, &vars);
    mlx_loop_hook(vars.mlx_ptr, draw_fract, &vars);
    mlx_loop(vars.mlx_ptr);
    return (0);
}

//gcc -lmlx -framework OpenGL -framework AppKit main.c && ./a.out
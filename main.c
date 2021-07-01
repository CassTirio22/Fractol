/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:02:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/01 18:55:20 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h>

static  void error(int argc, char *argv, t_var *vars)
{
    vars->data->id = 0; //SEGFAULT car pas encore malloc les struct
    if (argc != 2)
    {
        printf("ERROR!");
        exit(1);
    }
   // if (!strcmp(argv, "Mandelbrot"))
     //   vars->data->id = 0;
    //else if (!strcmp(argv, "Julia"))
      //  vars->data->id = 1;
}

int main(int argc, char **argv)
{
    t_var   vars;
    write(1, "OK\n", 3);
    error(argc, argv[1], &vars);
    init_var(&vars);
    mlx_hook(vars.win_ptr, 2, 1L<<0, &key_hook, &vars);
    draw_fract(&vars);
    mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, vars.img->img, 0, 0);
    mlx_loop(vars.mlx_ptr);
    return (0);
}

//gcc -lmlx -framework OpenGL -framework AppKit main.c && ./a.out
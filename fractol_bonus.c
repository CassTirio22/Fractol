/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:02:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/07 15:55:19 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_var   vars;
    
    init_var(&vars, argc, argv);
    error(argc, argv, &vars);
    return (0);
}

//gcc -lmlx -framework OpenGL -framework AppKit main.c && ./a.out
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:02:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/10 15:42:06 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int main(int argc, char **argv)
{
    t_var   vars;
    
    init_var(&vars, argc, argv);
    error(argc, argv, &vars);
    return (0);
}

//gcc -lmlx -framework OpenGL -framework AppKit main.c && ./a.out
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:02:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/08/22 17:53:41 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static int	check_arg(char *argv)
{
	if (!ft_strcmp(argv, "Mandelbrot"))
		return (0);
	else if (!ft_strcmp(argv, "Julia"))
		return (1);
	else if (!ft_strcmp(argv, "Burningship"))
		return (2);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_var	vars;

	if (argc >= 2)
	{
		vars.id = check_arg(argv[1]);
		if (vars.id != -1)
		{
			init_struct(&vars);
			init_var(&vars);
			init_mlx(&vars);
			init_threads(&vars);
			mlx_loop(vars.mlx_ptr);
		}
	}
	usage_msg();
	return (0);
}

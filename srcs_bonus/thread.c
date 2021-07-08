/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:56:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/08 17:37:46 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void    *use_threads(void *v)
{
    t_thread    *t;
    const int   thread_height = HEIGHT / THREADS;

    t = (t_thread *)v;
    t->vars->cord[1] = thread_height * t->id - 1;
    while (++t->vars->cord[1] < thread_height * (t->id + 1))
    {
        t->vars->cord[0] = -1;
        while (++t->vars->cord[0] < WIDTH)
            draw_fract(t->vars);
    }
    return (NULL);
}

void    init_threads(t_var *vars)
{
    int i;
    t_render    *r;

    i = -1;
    r = &vars->render;
    while (++i < THREADS)
    {
        r->args[i].id = i;
        r->args[i].vars = vars;
        if (pthread_create(r->threads + i, NULL, use_threads, r->args + i))
            ft_close();
    }
    while (i--)
        if (pthread_join(r->threads[i], NULL))
            ft_close();
}
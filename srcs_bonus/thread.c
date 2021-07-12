/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:56:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/12 16:39:42 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void    *use_threads(void *v)
{
    t_thread    *t;
    int         x;
    int         y;

    t = (t_thread *)v;
    y = HEIGHT / THREADS * t->id;
    while (++y < HEIGHT / THREADS * (t->id + 1))
    {
        x = -1;
        while (++x < WIDTH)
            draw_fract(t->vars, x, y);
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
        pthread_create(r->threads + i, NULL, use_threads, &(r->args[i]));
    }
    i = -1;
    write(1, "OK\n", 3);
    while (++i < THREADS)
        pthread_join(r->threads[i], NULL);
    write(1, "ok\n", 3);

}

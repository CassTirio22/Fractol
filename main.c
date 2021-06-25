/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:02:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/06/25 15:57:50 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

#define ITER_MAX 50

int main(void)
{
    float   x1 = -2.1;
    float   x2 = 0.6;
    float   y1 = -1.2;
    float   y2 = 1.2;
    float   image_x = 270;
    float   image_y = 240;
    float   zoom_x = image_x / (x2 - x1);
    float   zoom_y = image_y / (y2 - y1);
    float   c_r;
    float   c_i;
    float   z_r;
    float   z_i;
    float   i;
    int x = -1;
    int y;

    while (++x < image_x)
    {
        y = -1;
        while (++y < image_y)
        {
            c_r = x / zoom_x + x1;
            c_i = y / zoom_y + y1;
            z_r = 0;
            z_i = 0;
            i = 0;
        }
    }
}
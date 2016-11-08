/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:47:04 by sly               #+#    #+#             */
/*   Updated: 2015/05/21 17:18:42 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
//#include "../include/fdf.h"

void			draw(void *mlx, void *win)
{
/*	int			x;
	int			y;

	y = 100;
	while (y < 400)
	{
		x = 100;
		while (x < 300)
		{
			mlx_pixel_put(mlx, win, x++, y, 0xFF0000);
			//usleep(500);
		}
		y++;
	}*/
			//mlx_pixel_put(mlx, win, 300, 300, 0xFF0000);
	mlx_string_put(mlx, win, 200, 200, 0xFF0000, "hello");
}

int				expose_hook(t_param *p)
{
	//draw(p->mlx, p->win);
	mlx_string_put(p->mlx, p->win, 200, 200, 0xFF0000, "hello");
	return (0);
}

int				key_hook(int keycode, t_param *p)
{
	printf("key:%d\n", keycode);
	if (keycode == 53)
	{
		//mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	return (0);
}

void			display(t_param *p, int **tab, char *title)
{
	if (!(p->mlx = mlx_init()))
		exit(1);
	if (!(p->win = mlx_new_window(p->mlx, 960, 540, title)))
		exit(1);
	//printf("sizex:%d, sizey:%d\n", p->tblenx, p->tbleny);
	mlx_key_hook(p->win, &key_hook, &p);
	//mlx_expose_hook(p->win, &expose_hook, &p);
	mlx_string_put(p->mlx, p->win, 200, 200, 0xFF0000, "hello");
	//sleep(5);
	mlx_loop(p->mlx);
}

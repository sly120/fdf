/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maindemo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 15:52:57 by sly               #+#    #+#             */
/*   Updated: 2015/05/21 16:35:57 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			draw(void *mlx, void *win)
{
	int			x;
	int			y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

int				expose_hook(t_param *p)
{
	draw(p->mlx, p->win);
	return (0);
}

int				key_hook(int keycode, t_param *p)
{
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_param		p;

	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 420, 420, "42");
	mlx_expose_hook(p.win, expose_hook, &p);
	mlx_key_hook(p.win, key_hook, &p);
	mlx_loop(p.mlx);
	return (0);
}

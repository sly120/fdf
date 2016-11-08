/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 15:22:05 by sly               #+#    #+#             */
/*   Updated: 2015/05/28 15:47:20 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		expose_hook(t_param *p)
{
	draw(p);
	return (0);
}

int		key_hook(int keycode, t_param *p)
{
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	keycode == 15 ? p->xfactor += 0.25 : 0;
	keycode == 14 ? p->xfactor -= 0.25 : 0;
	keycode == 32 ? p->yfactor += 0.25 : 0;
	keycode == 34 ? p->yfactor -= 0.25 : 0;
	keycode == 67 ? p->zfactor += 0.5 : 0;
	keycode == 75 ? p->zfactor -= 0.5 : 0;
	keycode == 69 ? p->space += 5 : 0;
	keycode == 78 ? p->space -= 5 : 0;
	keycode == 123 ? p->originx -= 30 : 0;
	keycode == 126 ? p->originy -= 30 : 0;
	keycode == 124 ? p->originx += 30 : 0;
	keycode == 125 ? p->originy += 30 : 0;
	keycode == 2 ? p->alpha += 15 : 0;
	keycode == 3 ? p->alpha -= 15 : 0;
	keycode == 38 ? p->omega += 15 : 0;
	keycode == 40 ? p->omega -= 15 : 0;
	draw(p);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_param *p)
{
	if (button == 3)
	{
		p->originx = x + 500;
		p->originy = y;
	}
	button == 1 ? p->zfactor += 0.5 : 0;
	button == 2 ? p->zfactor -= 0.5 : 0;
	button == 4 ? p->space += 5 : 0;
	button == 5 ? p->space -= 5 : 0;
	draw(p);
	return (0);
}

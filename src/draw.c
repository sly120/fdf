/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 12:57:31 by sly               #+#    #+#             */
/*   Updated: 2015/05/28 13:10:54 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		draw_horizontals(t_param *p, t_point *pt, int x, int y)
{
	if (x < p->tablenx - 1)
	{
		p->x2 = x + 1;
		p->y2 = y;
		pt->x2 = xcalc(p, x + 1, y);
		pt->y2 = ycalc(p, x + 1, y);
		bresenham(p, pt);
	}
}

static void		draw_verticals(t_param *p, t_point *pt, int x, int y)
{
	if (y < p->tableny - 1)
	{
		p->x2 = x;
		p->y2 = y + 1;
		pt->x2 = xcalc(p, x, y + 1);
		pt->y2 = ycalc(p, x, y + 1);
		bresenham(p, pt);
	}
}

static void		draw_obliques(t_param *p, t_point *pt, int x, int y)
{
	if (x < p->tablenx - 1 && y < p->tableny - 1)
	{
		p->x2 = x + 1;
		p->y2 = y + 1;
		pt->x2 = xcalc(p, x + 1, y + 1);
		pt->y2 = ycalc(p, x + 1, y + 1);
		bresenham(p, pt);
	}
}

static void		draw_all_segments(t_param *p, int x, int y)
{
	t_point		pt;

	pt.x1 = xcalc(p, x, y);
	pt.y1 = ycalc(p, x, y);
	draw_horizontals(p, &pt, x, y);
	draw_verticals(p, &pt, x, y);
	draw_obliques(p, &pt, x, y);
}

void			draw(t_param *p)
{
	int			x;
	int			y;

	mlx_clear_window(p->mlx, p->win);
	legends(p);
	y = 0;
	while (y < p->tableny)
	{
		x = -1;
		while (++x < p->tablenx)
		{
			p->x1 = x;
			p->y1 = y;
			draw_all_segments(p, x, y);
		}
		y++;
	}
}

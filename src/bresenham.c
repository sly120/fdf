/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 15:02:58 by sly               #+#    #+#             */
/*   Updated: 2015/05/28 15:17:18 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		bresenham_part1(t_param *p, t_point *pt, int dx)
{
	int			dy;

	if ((dy = pt->y2 - pt->y1) != 0)
	{
		if (dy > 0)
			-dx >= dy ? segm_6(p, pt, dx, dy) : segm_7(p, pt, dx, dy);
		else
			dx <= dy ? segm_8(p, pt, dx, dy) : segm_9(p, pt, dx, dy);
	}
	else
		segm_10(p, pt);
}

static void		bresenham_part2(t_param *p, t_point *ptc, int dx)
{
	int			dy;
	t_point		pt;

	pt = *ptc;
	if ((dy = pt.y2 - pt.y1) != 0)
	{
		if (dy > 0)
			while (pt.y1 <= pt.y2)
				mlx_pixel_put(p->mlx, p->win, pt.x1, pt.y1++, customcolor(p));
		else
			while (pt.y1 >= pt.y2)
				mlx_pixel_put(p->mlx, p->win, pt.x1, pt.y1--, customcolor(p));
	}
}

void			bresenham(t_param *p, t_point *pt)
{
	int			dx;
	int			dy;

	if ((dx = pt->x2 - pt->x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = pt->y2 - pt->y1) != 0)
			{
				if (dy > 0)
					dx >= dy ? segm_1(p, pt, dx, dy) : segm_2(p, pt, dx, dy);
				else
					dx >= -dy ? segm_3(p, pt, dx, dy) : segm_4(p, pt, dx, dy);
			}
			else
				segm_5(p, pt);
		}
		else
			bresenham_part1(p, pt, dx);
	}
	else
		bresenham_part2(p, pt, dx);
}

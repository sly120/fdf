/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segments1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 15:05:45 by sly               #+#    #+#             */
/*   Updated: 2015/05/28 15:49:16 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			segm_1(t_param *p, t_point *ptc, int dx, int dy)
{
	int			e;
	t_point		pt;

	pt = *ptc;
	e = dx;
	dx *= 2;
	dy *= 2;
	while (pt.x1 <= pt.x2)
	{
		mlx_pixel_put(p->mlx, p->win, pt.x1++, pt.y1, customcolor(p));
		e -= dy;
		if (e < 0)
		{
			pt.y1++;
			e += dx;
		}
	}
}

void			segm_2(t_param *p, t_point *ptc, int dx, int dy)
{
	int			e;
	t_point		pt;

	pt = *ptc;
	e = dy;
	dx *= 2;
	dy *= 2;
	while (pt.y1 <= pt.y2)
	{
		mlx_pixel_put(p->mlx, p->win, pt.x1, pt.y1++, customcolor(p));
		e -= dx;
		if (e < 0)
		{
			pt.x1++;
			e += dy;
		}
	}
}

void			segm_3(t_param *p, t_point *ptc, int dx, int dy)
{
	int			e;
	t_point		pt;

	pt = *ptc;
	e = dx;
	dx *= 2;
	dy *= 2;
	while (pt.x1 <= pt.x2)
	{
		mlx_pixel_put(p->mlx, p->win, pt.x1++, pt.y1, customcolor(p));
		e += dy;
		if (e < 0)
		{
			pt.y1--;
			e += dx;
		}
	}
}

void			segm_4(t_param *p, t_point *ptc, int dx, int dy)
{
	int			e;
	t_point		pt;

	pt = *ptc;
	e = dy;
	dx *= 2;
	dy *= 2;
	while (pt.y1 >= pt.y2)
	{
		mlx_pixel_put(p->mlx, p->win, pt.x1, pt.y1--, customcolor(p));
		e += dx;
		if (e > 0)
		{
			pt.x1++;
			e += dy;
		}
	}
}

void			segm_5(t_param *p, t_point *ptc)
{
	t_point		pt;

	pt = *ptc;
	while (pt.x1 <= pt.x2)
		mlx_pixel_put(p->mlx, p->win, pt.x1++, pt.y1, customcolor(p));
	return ;
}

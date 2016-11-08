/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 18:48:16 by sly               #+#    #+#             */
/*   Updated: 2015/05/28 15:33:56 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				xcalc(t_param *p, int x, int y)
{
	int			calc;
	double		alpha;
	double		omega;

	alpha = p->alpha * M_PI / 180;
	omega = p->omega * M_PI / 180;
	calc = (int)(cos(omega) * (p->space * x * p->xfactor)
			- sin(omega) * (p->space * y * p->yfactor));
	return (p->originx / 2 + calc);
}

int				ycalc(t_param *p, int x, int y)
{
	int			calc;
	double		alpha;
	double		omega;

	alpha = p->alpha * M_PI / 180;
	omega = p->omega * M_PI / 180;
	calc = (int)(-sin(omega) * sin(alpha) * (p->space * x * p->xfactor)
			- cos(omega) * sin(alpha) * (p->space * y * p->yfactor)
			+ cos(alpha) * p->tab[y][x] * p->zfactor);
	return (p->originy / 2 + calc);
}

int				customcolor(t_param *p)
{
	int			result;
	int			progression;

	if ((-5 < p->tab[p->y1][p->x1] && p->tab[p->y1][p->x1] <= 0)
			|| (-5 < p->tab[p->y2][p->x2] && p->tab[p->y2][p->x2] <= 0))
		result = 0x00ED4A;
	else if ((0 < p->tab[p->y1][p->x1] && p->tab[p->y1][p->x1] <= 9)
			|| (0 < p->tab[p->y2][p->x2] && p->tab[p->y2][p->x2] <= 9))
		result = 0x247900;
	else if ((9 < p->tab[p->y1][p->x1] && p->tab[p->y1][p->x1] <= 25)
			|| (9 < p->tab[p->y2][p->x2] && p->tab[p->y2][p->x2] <= 25))
		result = 0xB7B100;
	else if ((25 < p->tab[p->y1][p->x1] && p->tab[p->y1][p->x1] <= 50)
			|| (25 < p->tab[p->y2][p->x2] && p->tab[p->y2][p->x2] <= 50))
		result = 0x503300;
	else if (p->tab[p->y1][p->x1] > 50 || p->tab[p->y2][p->x2] > 50)
		result = 0xFFFFFF;
	else
		result = 0x0000FF;
	return (result);
}

void			legends(t_param *p)
{
	mlx_string_put(p->mlx, p->win, 5, 0, 0xFFFFFF,
			"zoom:\t +/-/wheel up/wheel down");
	mlx_string_put(p->mlx, p->win, 5, 15, 0xFFFFFF,
			"move:\t arrow up/down/left/down/wheel clic");
	mlx_string_put(p->mlx, p->win, 5, 30, 0xFFFFFF,
			"vrotation:\t f/d");
	mlx_string_put(p->mlx, p->win, 5, 45, 0xFFFFFF,
			"hrotation:\t j/k");
	mlx_string_put(p->mlx, p->win, p->screenx - 105, 0, 0xFFFFFF,
			"x-/x+:\t e/r");
	mlx_string_put(p->mlx, p->win, p->screenx - 105, 15, 0xFFFFFF,
			"y+/y-:\t u/i");
	mlx_string_put(p->mlx, p->win, p->screenx - 305, 30, 0xFFFFFF,
			"z+/z-\t */'/' or mouse 1/mouse 2");
}

void			display(t_param p, char *title)
{
	if (!(p.mlx = mlx_init()))
		exit(1);
	if (!(p.win = mlx_new_window(p.mlx, p.screenx, p.screeny, title)))
		exit(1);
	mlx_expose_hook(p.win, expose_hook, &p);
	mlx_key_hook(p.win, key_hook, &p);
	mlx_mouse_hook(p.win, mouse_hook, &p);
	mlx_loop(p.mlx);
}

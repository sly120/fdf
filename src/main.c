/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 18:43:58 by sly               #+#    #+#             */
/*   Updated: 2015/05/27 21:24:33 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		initparam(t_param *p)
{
	int			screenx;
	int			screeny;

	p->space = 30;
	screenx = p->tablenx * p->space * 2;
	screeny = p->tableny * p->space * 2;
	p->screenx = screenx <= 2560 ? screenx : 2560;
	p->screeny = screeny <= 1440 ? screeny : 1440;
	p->xfactor = 1;
	p->yfactor = 1;
	p->zfactor = 1;
	p->originx = p->screenx;
	p->originy = p->screeny / 2;
	p->omega = 45.00;
	p->alpha = 215.26;
	p->bottom_color = 0xFF0000;
	p->top_color = 0xFFFFFF;
}

static void		fdf(char *src)
{
	t_param		param;

	param.tab = readfile(&param, src);
	initparam(&param);
	display(param, src);
	free(param.tab);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
		ft_putstr("\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 18:43:58 by sly               #+#    #+#             */
/*   Updated: 2015/05/19 17:40:29 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
//#include "../include/fdf.h"

static void		fdf(char *src)
{
	t_param		param;
	int			**tab;

	tab = readfile(&param, src);
	display(&param, tab, src);
	free(tab);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
		ft_putstr("\n");
	return (0);
}

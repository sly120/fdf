/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 21:43:55 by sly               #+#    #+#             */
/*   Updated: 2015/05/19 17:40:57 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
//#include "../include/fdf.h"

static int		ft_isspace_tab(int c)
{
	return (c == 9 || (c >= 11 && c <= 13) || c == 32);
}

static int		open_file(char *file)
{
	int			fd;
	int			ret;
	int			total;
	char		c;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit (1);
	total = 0;
	ret = 1;
	while (ret)
	{
		if ((ret = read(fd, &c, 1)) == -1)
			exit(1);
		if (!(ft_isdigit(c) || c == '\n' || c == '\0' || c == '-' || c == ' '))
			exit(1);
		total++;
	}
	close(fd);
	return (total);
}

static char		*copy_src(char *src, int size)
{
	char		*mapstr;
	int			fd;

	if ((fd = open(src, O_RDONLY)) == -1)
		exit(1);
	if (!(mapstr = (char*)malloc(sizeof(char) * (size + 1))))
		exit(1);
	read(fd, mapstr, size);
	mapstr[size] = '\0';
	close(fd);
	return (mapstr);
}

static void		getstatstr(char *mapstr, t_param *i)
{
	int			x;

	i->tblenx = -1;
	i->tbleny = 0;
	x = 0;
	while (*mapstr)
	{
		if (ft_isdigit(*mapstr) || *mapstr == '-')
			x++;
		while (ft_isdigit(*mapstr) || *mapstr == '-')
			mapstr++;
		if (*mapstr == '\n')
		{
			if (i->tblenx == -1)
				i->tblenx = x;
			else if (x != i->tblenx)
				exit(1);
			x = 0;
			i->tbleny++, mapstr++;
		}
		if (*mapstr)
			while (ft_isspace(*mapstr))
				mapstr++;
	}
}

static int		**createtab(t_param *i)
{
	int			y;

	int			**tab;

	if (!(tab = (int**)malloc(sizeof(int*) * i->tbleny)))
		exit(1);
	y = 0;
	while (y < i->tbleny)
		if (!(tab[y++] = (int*)malloc(sizeof(int) * i->tblenx)))
			exit(1);
	return (tab);
}

static int		ft_strlensp(char *s)
{
	return (*s && !(ft_isspace(*s)) && *s != '\n' ? ft_strlensp(++s) + 1 : 0);
}

static void		strtointab(char *mapstr, int ***tb, t_param *param)
{
	int			x;
	int			y;
	int			len;

	y = 0;
	x = 0;
	len = -1;
	while (*mapstr)
	{
		while (ft_isspace_tab(*mapstr))
			mapstr++;
		if (*mapstr)
		{
			if (*mapstr == '\n')
			{
				len == -1 ? len = x : 0;
				len != -1 && len != x ? exit (1) : 0;
				x = 0;
				y++, mapstr++;
			}
			*mapstr ? (*tb)[y][x++] = atoi(mapstr) : 0;
		}
		mapstr += ft_strlensp(mapstr);
	}
}
/*
static void		printinttb(int **tab, t_param *param)
{
	int			x;
	int			y;

	y = 0;
		printf("tblenx:%d, tbleny:%d\n", param->tblenx, param->tbleny);
	while (y < param->tbleny)
	{
		x = 0;
		printf("y:%d", y);
		while (x < param->tblenx)
			printf("[%d] ", tab[y][x++]);
		y++;
	}
}
*/
int				**readfile(t_param *param, char *src)
{
	char		*mapstr;
	int			**tb;
	int			i;

	i = open_file(src);
	mapstr = copy_src(src, i);
	getstatstr(mapstr, param);
	tb = createtab(param);
	strtointab(mapstr, &tb, param);
	free(mapstr);
	//printinttb(tb, param);
	//printf("total:%d\n", i);
	return (tb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 18:46:00 by sly               #+#    #+#             */
/*   Updated: 2015/05/28 15:27:08 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FDF_H
#define FDF_H

#include <stdio.h>

#include <libft.h>
#include <fcntl.h>
#include "../minilibx_macos/mlx.h"
#include <math.h>

typedef struct		s_param
{
	void			*mlx;
	void			*win;
	int				screenx;
	int				screeny;
	int				**tab;
	int				tablenx;
	int				tableny;
	int				tabminz;
	int				tabmaxz;
	int				originx;
	int				originy;
	double			xfactor;
	double			yfactor;
	double			zfactor;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	double			alpha;
	double			omega;
	int				space;
	int				bottom_color;
	int				top_color;
}					t_param;

typedef struct		s_point
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_point;

int					**readfile(t_param *p, char *path);
int					open_file(char *file);
char				*copy_src(char *src, int size);
int					**createtab(t_param *i);

void				display(t_param p, char *title);
int					xcalc(t_param *p, int x, int y);
int					ycalc(t_param *p, int x, int y);
void				draw(t_param *p);
void				legends(t_param *p);
void				bresenham(t_param *p, t_point *pt);
void				segm_1(t_param *p, t_point *ptc, int dx, int dy);
void				segm_2(t_param *p, t_point *ptc, int dx, int dy);
void				segm_3(t_param *p, t_point *ptc, int dx, int dy);
void				segm_4(t_param *p, t_point *ptc, int dx, int dy);
void				segm_5(t_param *p, t_point *ptc);
void				segm_6(t_param *p, t_point *ptc, int dx, int dy);
void				segm_7(t_param *p, t_point *ptc, int dx, int dy);
void				segm_8(t_param *p, t_point *ptc, int dx, int dy);
void				segm_9(t_param *p, t_point *ptc, int dx, int dy);
void				segm_10(t_param *p, t_point *ptc);
int					customcolor(t_param *p);
int					expose_hook(t_param *p);
int					key_hook(int keycode, t_param *p);
int					mouse_hook(int button, int x, int y, t_param *p);
#	endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:29:52 by mchepil           #+#    #+#             */
/*   Updated: 2018/05/30 15:29:56 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_project_fdf.h"

int			fdf_val_return(int y, int nb, int save)
{
	if (y == 0)
		return (nb);
	else if (save == nb)
		return (save);
	else
		return (-1);
}

size_t		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void		fdf_draw_line(t_project_fdf *draw, int *tabxy, int x, int y)
{
	int		tab_x[2];
	int		tab_y[2];
	int		e[2];
	int		x0;
	int		y0;

	x0 = tabxy[0];
	y0 = tabxy[1];
	tab_x[0] = ft_abs(x - x0);
	tab_x[1] = ft_cor_x(x0, x);
	tab_y[0] = ft_abs(y - y0);
	tab_y[1] = ft_cor_y(y0, y);
	e[0] = (tab_x[0] > tab_y[0] ? tab_x[0] : -tab_y[0]) / 2;
	while (x0 != x || y0 != y)
	{
		mlx_pixel_put(draw->mlx, draw->win, x0, y0, draw->color);
		e[1] = e[0];
		e[1] > -tab_x[0] ? e[0] -= tab_y[0] : 1 == 1;
		e[1] > -tab_x[0] ? x0 += tab_x[1] : 1 == 1;
		e[1] < tab_y[0] ? e[0] += tab_x[0] : 1 == 1;
		e[1] < tab_y[0] ? y0 += tab_y[1] : 1 == 1;
	}
}

void		fdf_draw_all_lines(t_project_fdf *draw, int x, int y)
{
	int		tabxy[2];

	tabxy[0] = draw->dx + (x - y);
	tabxy[1] = draw->dy + draw->map[y / draw->sy][x / draw->sx] * draw->z
		+ x + y;
	if (x / draw->sx < draw->chars - 1 && y / draw->sy < draw->lines)
		fdf_draw_line(draw, tabxy, draw->dx + ((x + draw->sx) - y),
		draw->dy + draw->map[y / draw->sy][x / draw->sx + 1] * draw->z +
		(x + draw->sx) + y);
	if (y / draw->sy < draw->lines - 1 && x / draw->sx < draw->chars)
		fdf_draw_line(draw, tabxy, draw->dx + (x - (y + draw->sy)),
		draw->dy + draw->map[y / draw->sy + 1][x / draw->sx] * draw->z +
		x + (y + draw->sy));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:59:22 by mchepil           #+#    #+#             */
/*   Updated: 2018/05/26 17:59:24 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_project_fdf.h"

void	fdf_check_draw(t_project_fdf *draw)
{
	if (draw->check == 0)
	{
		draw->z = -5;
		draw->dx = 1280 * 0.4;
		draw->dy = 20;
		draw->sx = (1280 * 0.7) / (draw->chars - 1);
		draw->sy = (720 * 0.5) / (draw->lines - 1);
		draw->color = 0x00FF00;
	}
	draw->check++;
}

void	fdf_draw(t_project_fdf *draw)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	fdf_check_draw(draw);
	while (x / draw->sx < draw->chars || y / draw->sy < draw->lines - 1)
	{
		if (x / draw->sx == draw->chars)
		{
			x = 0;
			y += draw->sy;
		}
		fdf_draw_all_lines(draw, x, y);
		x += draw->sx;
	}
}

void	fdf_error(t_project_fdf *main, t_cor *cor)
{
	if (fdf_parser(main, cor) == -1)
	{
		write(1, "error: not a valid file or map\n", 31);
		return ;
	}
	fdf_mlx(main);
}

int		main(int ac, char **av)
{
	t_project_fdf	main;
	t_cor			*cor;

	if (ac == 2)
	{
		cor->name = av[1];
		cor->fd = open(cor->name, O_RDONLY);
		fdf_error(&main, cor);
	}
	else
		write(1, "usage: ./fdf file\n", 18);
	return (0);
}

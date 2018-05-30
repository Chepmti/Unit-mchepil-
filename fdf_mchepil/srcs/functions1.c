/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:58:08 by mchepil           #+#    #+#             */
/*   Updated: 2018/05/26 18:19:23 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_project_fdf.h"

int			fdf_keyboard(int code, t_project_fdf *key)
{
	fdf_esc(code);
	fdf_up_and_down(code, key);
	fdf_zoom(code, key);
	fdf_decal(code, key);
	return (0);
}

void		fdf_up_and_down(int code, t_project_fdf *key)
{
	if (code == 67)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z++;
		fdf_draw(key);
	}
	if (code == 75)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z--;
		fdf_draw(key);
	}
}

int			fdf_exit(void)
{
	exit(0);
	return (0);
}

void		fdf_esc(int code)
{
	if (code == 53)
		exit(0);
}

void		fdf_mlx(t_project_fdf *key)
{
	key->check = 0;
	key->mlx = mlx_init();
	key->win = mlx_new_window(key->mlx, 1280, 720, "my_top_diagram");
	fdf_draw(key);
	mlx_key_hook(key->win, fdf_keyboard, key);
	mlx_hook(key->win, 17, (1L << 25), fdf_exit, key);
	mlx_loop(key->mlx);
}

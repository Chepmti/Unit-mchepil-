/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:10:21 by mchepil           #+#    #+#             */
/*   Updated: 2018/05/26 18:10:38 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_project_fdf.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	s1 = (char *)dst;
	s2 = (const char *)src;
	i = 0;
	if (s1 < s2)
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
		{
			s1[len] = s2[len];
		}
	}
	return (dst);
}

void		fdf_zoom(int keycode, t_project_fdf *key)
{
	zoom_max(keycode, key);
	zoom_min(keycode, key);
}

void		zoom_max(int keycode, t_project_fdf *key)
{
	if (keycode == 69 && key->sx * 2 <= 500 && key->sy * 2 <= 500)
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 2;
		key->sy *= 2;
		key->z *= 2;
		fdf_draw(key);
	}
}

void		zoom_min(int keycode, t_project_fdf *key)
{
	if (keycode == 78 && key->sx * 0.5 >= 1 && key->sy * 0.5 >= 1 &&
		(-key->z * 0.5 >= 1 || key->z * 0.5 >= 1))
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 0.5;
		key->sy *= 0.5;
		key->z *= 0.5;
		fdf_draw(key);
	}
}

void		fdf_decal(int keycode, t_project_fdf *key)
{
	if (keycode >= 123 && keycode <= 126)
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == 123)
			key->dx = key->dx - 20;
		if (keycode == 126)
			key->dy = key->dy - 20;
		if (keycode == 124)
			key->dx = key->dx + 20;
		if (keycode == 125)
			key->dy = key->dy + 20;
		if (keycode == 15)
			key->check = 0;
		fdf_draw(key);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:31:23 by mchepil           #+#    #+#             */
/*   Updated: 2018/05/30 15:31:25 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_project_fdf.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	if (n)
	{
		d = dst;
		while (i < n)
		{
			d[i] = c;
			i++;
		}
	}
	return (dst);
}

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

int		fdf_helper_all_tab(t_project_fdf *parse, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	if (parse->lines == 0)
		parse->chars = x;
	else
	{
		if (x != parse->chars)
			return (-1);
	}
	free(line);
	free(tab);
	parse->lines++;
	return (0);
}

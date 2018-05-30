/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:58:53 by mchepil           #+#    #+#             */
/*   Updated: 2018/05/26 17:58:54 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_project_fdf.h"

int		fdf_malloc_tab(t_project_fdf *parse, t_cor *cor)
{
	char	*line;
	int		gnl_line;

	line = NULL;
	parse->lines = 0;
	parse->chars = 0;
	while ((gnl_line = get_next_line(cor->fd, &line)) > 0)
	{
		if (fdf_helper_all_tab(parse, line) == -1)
			return (-1);
	}
	parse->map = ft_memalloc(sizeof(int*) * parse->lines);
	close(cor->fd);
	cor->fd = open(cor->name, O_RDONLY);
	return (0);
}

int		fdf_check_line(char *str, int y, int save)
{
	int corect;
	int nb;

	nb = 0;
	corect = check(str, y, save, nb);
	return (corect);
}

int		ft_atoi(const char *str)
{
	long			res;
	long			sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (TABS(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res > 99999999999 && sign == 1)
			return (-1);
		else if (res < -99999999999 && sign == -1)
			return (0);
		i++;
	}
	return ((int)res * (int)sign);
}

void	ft_memdel(void **ap)
{
	if (*ap)
		free(*ap);
	*ap = NULL;
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

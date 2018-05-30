/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:30:43 by mchepil           #+#    #+#             */
/*   Updated: 2018/05/30 15:30:45 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_project_fdf.h"

int		check(char *str, int y, int save, int nb)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (str[i] != ' ')
				return (-1);
			k = 0;
		}
		else
		{
			if (k == 0)
				nb++;
			k++;
		}
		i++;
	}
	return (fdf_val_return(y, nb, save));
}

int		fdf_parser(t_project_fdf *parse, t_cor *cor)
{
	char	*line;
	char	**tab;
	int		nanotech[3];

	nanotech[1] = 0;
	if (fdf_malloc_tab(parse, cor) == -1)
		return (-1);
	while ((nanotech[2] = get_next_line(cor->fd, &line)) > 0)
	{
		nanotech[0] = 0;
		tab = ft_strsplit(line, ' ');
		free(line);
		parse->map[nanotech[1]] = ft_memalloc(sizeof(int) * parse->chars);
		while (tab[nanotech[0]] != NULL)
		{
			parse->map[nanotech[1]][nanotech[0]] = ft_atoi(tab[nanotech[0]]);
			free(tab[nanotech[0]]);
			nanotech[0]++;
		}
		free(tab);
		nanotech[1]++;
	}
	return ((nanotech[2] == -1) ? -1 : 0);
}

int		ft_read_write(int fd, char **res, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		j;
	t_lst	ft_tmp;

	while ((j = read(fd, buf, BUFF_SIZE)))
	{
		if (j == -1)
			return (-1);
		buf[j] = ENDL;
		ft_tmp.tmp = NULL;
		if (*res)
		{
			ft_tmp.tmp = ft_strdup(*res);
			ft_strdel(res);
			*res = ft_strjoin(ft_tmp.tmp, buf);
			ft_memdel((void **)&ft_tmp.tmp);
		}
		else
			*res = ft_strdup(buf);
		if (ft_res(res, line))
			return (1);
	}
	return (0);
}

int		ft_res(char **res, char **line)
{
	t_lst	st_line;

	st_line.str = ft_strchr(*res, END);
	if (st_line.str)
	{
		*line = ft_strsub(*res, 0, st_line.str - *res);
		ft_memmove(*res, st_line.str + 1, ft_strlen(st_line.str));
		st_line.str = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*res[FD_MAX];
	t_lst			st_res;

	if (!line || fd < 0 || fd > FD_MAX)
		return (-1);
	if (res[fd] && ft_res(&res[fd], line))
		return (1);
	st_res.final = ft_read_write(fd, &res[fd], line);
	if (st_res.final != 0)
		return (st_res.final);
	if (res[fd] == NULL || res[fd][0] == ENDL)
		return (0);
	*line = res[fd];
	res[fd] = NULL;
	return (1);
}

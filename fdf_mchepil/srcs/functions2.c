/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:58:16 by mchepil           #+#    #+#             */
/*   Updated: 2018/05/26 17:58:19 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_project_fdf.h"

int					ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static size_t		ft_len_c_stop(const char *str, int start, char c_stop)
{
	size_t		cnt;

	if (!str)
		return (0);
	cnt = 0;
	while (str[start] && (str[start] != c_stop))
	{
		start++;
		cnt++;
	}
	return (cnt);
}

static int			ft_split_count(char *str, char c)
{
	int		cnt_wrd;
	int		cnt;

	cnt = 0;
	cnt_wrd = 0;
	while (str[cnt])
	{
		while (str[cnt] && str[cnt] != c)
			cnt++;
		while (str[cnt] && str[cnt] == c)
			cnt++;
		cnt_wrd++;
	}
	return (cnt_wrd);
}

char				**ft_strsplit(char *s, char c)
{
	int				cnt_wrd;
	int				i;
	int				cnt;
	char			**tmp;
	char			*str;

	str = (char *)s;
	if (!str || *str == 0)
		return (NULL);
	cnt = 0;
	cnt_wrd = ft_split_count(str, c);
	tmp = (char**)ft_memalloc(sizeof(char*) * (cnt_wrd + 1));
	cnt = 0;
	i = 0;
	while (i < cnt_wrd)
	{
		while ((str[cnt] == (char)c) && str[cnt])
			cnt++;
		tmp[i] = ft_strsub(str, cnt, ft_len_c_stop(str, cnt, c));
		while ((str[cnt] != (char)c) && str[cnt])
			cnt++;
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

void				*ft_memalloc(size_t size)
{
	void	*m;

	m = malloc(size);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, size);
	return (m);
}

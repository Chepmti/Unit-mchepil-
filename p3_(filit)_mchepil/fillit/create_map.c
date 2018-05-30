/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpanasen <mpanasen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:56:16 by mpanasen          #+#    #+#             */
/*   Updated: 2017/11/30 16:36:56 by mpanasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_map_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	ft_bzero(str, size + 1);
	while (++i < size)
		str[i] = '.';
	return (str);
}

char	*ft_map_init(void)
{
	char	*ret;
	char	*tmp1;
	char	*tmp2;
	int		i;

	i = -1;
	while (++i < 4)
	{
		tmp1 = ft_map_strnew(4);
		tmp2 = ret;
		(i != 0) ? (ret = ft_strjoin(tmp2, tmp1)) :
			(ret = ft_strdup(tmp1));
		ft_strdel(&tmp1);
		tmp1 = ft_strjoin(ret, "\n");
		ft_strdel(&ret);
		ret = tmp1;
	}
	return (ret);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:54:53 by mchepil           #+#    #+#             */
/*   Updated: 2017/11/30 18:29:19 by mpanasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

void	ft_put_on_map(int *fig, char **map, char byckovka)
{
	int i;

	i = -1;
	while (++i < 4)
		map[0][fig[i]] = byckovka;
}

int		main(int argc, char *argv[])
{
	int i;
	int f;
	char c;
	char *map;
	int fd;

//	str = (char *)malloc(sizeof(i) * 10000);
//	fd = open(argv[1], O_RDONLY);
//	while (read(fd, &c, 1))
//	{
//		str[i] = c;
//		i++;
//	}
//	close(fd);
	int **fig;
	fig = (int**)malloc(sizeof(int*) * 3);
	fig[0] = (int*)malloc(sizeof(int) * 4);
	fig[0][0] = 0;
	fig[0][1] = 5;
	fig[0][2] = 10;
	fig[0][3] = 11;
	fig[1] = (int*)malloc(sizeof(int) * 4);
	fig[1][0] = 1;
	fig[1][1] = 5;
	fig[1][2] = 6;
	fig[1][3] = 7;
	fig[2] = (int*)malloc(sizeof(int) * 4);
	fig[2][0] = 0;
	fig[2][1] = 1;
	fig[2][2] = 2;
	fig[2][3] = 3;
	printf("%s\n", ft_map_init());
	map = ft_map_init();
	ft_tipa_copy(fig, &map, 3);
	printf("%s\n", map);
	return(0);
}

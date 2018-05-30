/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pray_for_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpanasen <mpanasen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:40:39 by mpanasen          #+#    #+#             */
/*   Updated: 2017/11/30 19:06:52 by mpanasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tipa_copy(int **gaay, char **lalka, int fig_count)
{
	int		i;
	char	a;

	i = -1;
	a = 'A';
	while (++i < fig_count)
	{
		ft_put_on_map(gaay[i], lalka, a);
		a++;
	}
}

int		ft_mix_shit(int **a, int figures)
{
	int		k;
	int		n;

	k = -1;
	n = -1;
	while (++k < figures)
	{
		while (++n < 4)
		{
			if(a[k][n] == a[k + 1][n] && a[k + 1][n] + 1 != 4 &&)
			{
			while (a[k+1][n]  )
			}
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:34:54 by mchepil           #+#    #+#             */
/*   Updated: 2017/11/30 18:27:44 by mpanasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>/////////////////////////////////////////////////////////////////
# include "libft/libft.h"

void				ft_error(void);
char				*ft_map_strnew(size_t size);
int					ft_basic_check(char *reading);
void				ft_supercheck(char *s);
char				*ft_map_init(void);
void				ft_put_on_map(int *a, char **b, char c);
void				ft_tipa_copy(int **a, char **b, int c);
int					valid_file(int fd);
int					valid_blocks(char **arr);
int					*block_indexes(char *row);

#endif

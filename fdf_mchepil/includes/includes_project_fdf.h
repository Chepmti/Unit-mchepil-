/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_project_fdf.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:33:36 by mchepil           #+#    #+#             */
/*   Updated: 2018/05/26 18:33:38 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_PROJECT_FDF_H
# define INCLUDES_PROJECT_FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define TABS(a) a == ' ' || (a >= 9 && a <= 13)
# define BUFF_SIZE 1
# define FD_MAX 2147483647
# define END '\n'
# define ENDL '\0'

typedef struct		s_project_fdf
{
	void			*mlx;
	void			*win;
	int				**map;
	int				lines;
	int				check;
	int				chars;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	unsigned long	color;
}					t_project_fdf;

typedef struct		s_cor
{
	char			*name;
	int				fd;
}					t_cor;

typedef struct		s_lst
{
	int			final;
	char		*str;
	char		*tmp;
}					t_lst;

size_t				ft_abs(int n);
int					ft_cor_x(int x0, int x);
int					ft_cor_y(int y0, int y);
void				zoom_max(int keycode, t_project_fdf *key);
void				zoom_min(int keycode, t_project_fdf *key);
int					check(char *str, int y, int save, int nb);
int					ft_atoi(const char *str);
void				ft_memdel(void **ap);
void				fdf_esc(int code);
void				fdf_up_and_down(int code, t_project_fdf *key);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strchr(const char *s, int c);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
void				fdf_draw(t_project_fdf *draw);
int					ft_isdigit(int c);
char				**ft_strsplit(char *s, char c);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *dst, int c, size_t n);
char				*ft_strsub(char *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
int					fdf_exit(void);
void				fdf_zoom(int keycode, t_project_fdf *key);
void				fdf_error(t_project_fdf *parse, t_cor *cor);
int					fdf_parser(t_project_fdf *parse, t_cor *cor);
int					get_next_line(const int fd, char **line);
int					ft_res(char **res, char **line);
int					ft_read_write(int fd, char **res, char **line);
void				fdf_draw_all_lines(t_project_fdf *draw, int x, int y);
void				fdf_check_env(t_project_fdf *draw);
void				fdf_draw_line(t_project_fdf *draw, int *tabxy, int x, \
																int y);
void				fdf_mlx(t_project_fdf *key);
int					fdf_keyboard(int keycode, t_project_fdf *key);
void				fdf_decal(int keycode, t_project_fdf *key);
int					fdf_malloc_tab(t_project_fdf *parse, t_cor *cor);
int					fdf_helper_all_tab(t_project_fdf *parse, char *line);
int					fdf_check_line(char *str, int y, int save);
int					fdf_val_return(int y, int nb, int save);

#endif

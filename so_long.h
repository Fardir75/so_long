/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:26:11 by eavilov           #+#    #+#             */
/*   Updated: 2022/04/04 13:34:19 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*  🐄 Libs 🐄 	*/

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./minilibx_opengl_20191021/mlx.h"

/* Mes 🐄 strrustrcerutures 🐄 */

typedef struct s_struc {
	void	*mlx;
	void	*win;
	void	*herodown;
	void	*heroup;
	void	*heroleft;
	void	*heroright;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*item;
	char	readcont[9999];
	char	*message;
	int		count;
	int		*coords;
	int		*res;
	int		itemcount;
	int		pos;
	int		x;
	int		y;
	int		s1;
	int		s2;
}			t_struc;

typedef struct s_assets {
	int		player;
	int		item;
	int		exit;
}			t_assets;

/* Keycode du claviers */

// Echap = 53
// A = 0
// S = 1
// W = 13
// D = 2

/*	 🐄 Fonctions 🐄	*/

void	ft_putstr(char *str);
void	ft_counter(t_struc *vars);
void	ft_initiation(t_struc *vars);
void	ft_put_floor(t_struc *vars);
void	ft_wall_placer(t_struc *vars);
void	ft_floor_placer(t_struc *vars);
void	ft_put_player(t_struc *vars);
void	ft_put_exit(t_struc *vars);
void	ft_put_item(t_struc *vars);
void	ft_others_placer(t_struc *vars);
void	ft_trans_right(t_struc *vars);
void	ft_trans_down(t_struc *vars, int column);
void	ft_trans_left(t_struc *vars);
void	ft_trans_up(t_struc *vars, int column);
void	ft_reader(char *map, t_struc *vars);

char	*ft_strtjoin(char const *s1, char const *s2, char const *s3);
char	*ft_strdup(char *src);
char	count(int nb);
char	*ft_itoa(int n);
char	*ft_strrdup(char const *src, char c);
char	**ft_split(char const *s, char c);
char	*ft_message_builder(void);

int		ft_freesbee(char **string);
int		mlx_move(int keycode, t_struc *vars);
int		countchar(char const *s, char c);
int		*ft_fetch_coords(t_struc *vars);
int		ft_strlen(const char *s);
int		ft_mlx_close(t_struc *vars); // 🐄
int		ft_is_rectangular(char *map, t_struc *vars);
int		ft_isthere_asset(char *map, t_struc *vars, t_assets *content);
int		ft_hero_move_right(t_struc *vars);
int		ft_hero_move_down(t_struc *vars, int column);
int		ft_hero_move_left(t_struc *vars);
int		ft_hero_move_up(t_struc *vars, int column);
int		ft_is_closed(char *map);
int		ft_map_checker(t_struc *vars, t_assets *content);
int		ft_map_parser(t_struc *vars, t_assets *content);
int		ft_format_checker(char *map);

/* 		 🐄 Fin 🐄 		*/
#endif
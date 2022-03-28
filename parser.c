/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:59:13 by eavilov           #+#    #+#             */
/*   Updated: 2022/03/28 15:59:13 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wall_placer(t_struc *vars)
{
	int	i;

	i = 0;
	ft_initiation(&*vars);
	while (vars->readcont[i])
	{
		if (vars->readcont[i] == '1')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, vars->x, vars->y);
			vars->x = vars->x + 64;
		}
		else if (vars->readcont[i] == '\n')
		{
			vars->y = vars->y + 64;
			vars->x = 0;
		}
		else
			vars->x = vars->x + 64;
		i++;
	}
	return ;
}

void	ft_floor_placer(t_struc *vars)
{
	int	i;

	i = 0;
	ft_initiation(&*vars);
	while (vars->readcont[i])
	{
		if (vars->readcont[i] == '0')
			ft_put_floor(&*vars);
		else if (vars->readcont[i] == '\n')
		{
			vars->y = vars->y + 64;
			vars->x = 0;
		}
		else
			vars->x = vars->x + 64;
		i++;
	}
	return ;
}

void	ft_others_placer(t_struc *vars)
{
	int	i;

	i = 0;
	ft_initiation(&*vars);
	while (vars->readcont[i])
	{
		if (vars->readcont[i] == 'P')
			ft_put_player(&*vars);
		else if (vars->readcont[i] == 'E')
			ft_put_exit(&*vars);
		else if (vars->readcont[i] == 'C')
			ft_put_item(&*vars);
		else if (vars->readcont[i] == '\n')
		{
			vars->y = vars->y + 64;
			vars->x = 0;
		}
		else
			vars->x = vars->x + 64;
		i++;
	}
	return ;
}

int		ft_map_parser(char *map, t_struc *vars)
{
	int	check;

	check = ft_map_checker(map, &*vars);
	if (check == 0)
		return(0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->res[0] * 64, vars->res[1] * 64, "C'EST MON SO_LONG");
	ft_wall_placer(&*vars);
	ft_floor_placer(&*vars);
	ft_others_placer(&*vars);
	while (vars->readcont[vars->pos] != 'P')
		vars->pos++;
	return (1);
}

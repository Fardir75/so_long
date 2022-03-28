/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:59:30 by eavilov           #+#    #+#             */
/*   Updated: 2022/03/28 15:59:30 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_struc *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, vars->x, vars->y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->hero, vars->x, vars->y);
	vars->x = vars->x + 64;
	return ;
}

void	ft_put_exit(t_struc *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, vars->x, vars->y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, vars->x - 10, vars->y + 26);
	vars->x = vars->x + 64;
	return ;
}

void	ft_put_item(t_struc *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, vars->x, vars->y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->item, vars->x + 6, vars->y + 16);
	vars->x = vars->x + 64;
	return ;
}

void	ft_put_floor(t_struc *vars)
{
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "./assets/floor.xpm", &vars->s1, &vars->s2);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, vars->x, vars->y);
	vars->x = vars->x + 64;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:20:50 by eavilov           #+#    #+#             */
/*   Updated: 2022/03/30 10:26:42 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_trans_right(t_struc *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->floor, vars->x, vars->y);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->exit, vars->x - 10, vars->y + 26);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->heroright, vars->x + 82, vars->y);
	vars->x = vars->x + 64;
	vars->pos++;
	return ;
}

void	ft_trans_down(t_struc *vars, int column)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->floor, vars->x, vars->y);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->exit, vars->x - 10, vars->y + 26);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->herodown, vars->x + 18, vars->y + 64);
	vars->y = vars->y + 64;
	vars->pos = vars->pos + column + 1;
	return ;
}

void	ft_trans_left(t_struc *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->floor, vars->x, vars->y);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->exit, vars->x - 10, vars->y + 26);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->heroleft, vars->x - 46, vars->y);
	vars->x = vars->x - 64;
	vars->pos--;
	return ;
}

void	ft_trans_up(t_struc *vars, int column)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->floor, vars->x, vars->y);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->exit, vars->x - 10, vars->y + 26);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->heroup, vars->x + 18, vars->y - 64);
	vars->y = vars->y - 64;
	vars->pos = vars->pos - column - 1;
	return ;
}

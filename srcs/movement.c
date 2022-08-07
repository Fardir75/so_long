/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:59:36 by eavilov           #+#    #+#             */
/*   Updated: 2022/03/30 10:26:21 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_hero_move_right(t_struc *vars)
{
	if (vars->readcont[vars->pos + 1] != '1')
	{
		ft_counter(&*vars);
		if (vars->readcont[vars->pos + 1] == 'C')
		{
			vars->itemcount--;
			vars->readcont[vars->pos + 1] = '0';
		}
		else if (vars->readcont[vars->pos + 1] == 'E'
			&& vars->itemcount == 0)
			ft_mlx_close(&*vars);
		else if (vars->readcont[vars->pos] == 'E')
		{
			ft_trans_right(&*vars);
			return (0);
		}
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->floor, vars->x, vars->y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->heroright, vars->x + 82, vars->y);
		vars->x = vars->x + 64;
		vars->pos++;
	}
	return (0);
}

int	ft_hero_move_down(t_struc *vars, int column)
{
	if (vars->readcont[vars->pos + column + 1] != '1')
	{
		ft_counter(&*vars);
		if (vars->readcont[vars->pos + column + 1] == 'C')
		{
			vars->itemcount--;
			vars->readcont[vars->pos + column + 1] = '0';
		}
		else if (vars->readcont[vars->pos + column + 1] == 'E'
			&& vars->itemcount == 0)
			ft_mlx_close(&*vars);
		else if (vars->readcont[vars->pos] == 'E')
		{
			ft_trans_down(&*vars, column);
			return (0);
		}
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->floor, vars->x, vars->y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->herodown, vars->x + 18, vars->y + 64);
		vars->y = vars->y + 64;
		vars->pos = vars->pos + column + 1;
	}
	return (0);
}

int	ft_hero_move_left(t_struc *vars)
{
	if (vars->readcont[vars->pos - 1] != '1')
	{
		ft_counter(&*vars);
		if (vars->readcont[vars->pos - 1] == 'C')
		{
			vars->itemcount--;
			vars->readcont[vars->pos - 1] = '0';
		}
		else if (vars->readcont[vars->pos - 1] == 'E'
			&& vars->itemcount == 0)
			ft_mlx_close(&*vars);
		else if (vars->readcont[vars->pos] == 'E')
		{
			ft_trans_left(&*vars);
			return (0);
		}
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->floor, vars->x, vars->y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->heroleft, vars->x - 46, vars->y);
		vars->x = vars->x - 64;
		vars->pos--;
	}
	return (0);
}

int	ft_hero_move_up(t_struc *vars, int column)
{
	if (vars->readcont[vars->pos - column - 1] != '1')
	{
		ft_counter(&*vars);
		if (vars->readcont[vars->pos - column - 1] == 'C')
		{
			vars->itemcount--;
			vars->readcont[vars->pos - column - 1] = '0';
		}
		else if (vars->readcont[vars->pos - column - 1] == 'E'
			&& vars->itemcount == 0)
			ft_mlx_close(&*vars);
		else if (vars->readcont[vars->pos] == 'E')
		{
			ft_trans_up(&*vars, column);
			return (0);
		}
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->floor, vars->x, vars->y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->heroup, vars->x + 18, vars->y - 64);
		vars->y = vars->y - 64;
		vars->pos = vars->pos - column - 1;
	}
	return (0);
}

int	mlx_move(int keycode, t_struc *vars)
{
	int	column;

	column = 0;
	while (vars->readcont[column] != '\n')
		column++;
	if (keycode == 53)
		ft_mlx_close(&*vars);
	else if (keycode == 2)
		ft_hero_move_right(&*vars);
	else if (keycode == 1)
		ft_hero_move_down(&*vars, column);
	else if (keycode == 0)
		ft_hero_move_left(&*vars);
	else if (keycode == 13)
		ft_hero_move_up(&*vars, column);
	return (0);
}

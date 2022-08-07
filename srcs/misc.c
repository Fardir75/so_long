/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:59:19 by eavilov           #+#    #+#             */
/*   Updated: 2022/04/02 14:15:19 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_mlx_close(t_struc *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	*ft_fetch_coords(t_struc *vars)
{
	int	index;
	int	*coord;

	index = 0;
	vars->x = 0;
	vars->y = 0;
	coord = (int *)malloc(sizeof(int) * 2);
	while (vars->readcont[index])
	{
		if (vars->readcont[index] == '\n')
		{
			vars->x = 0;
			vars->y = vars->y + 64;
		}
		if (vars->readcont[index] == 'P')
		{
			coord[0] = vars->x - 64;
			coord[1] = vars->y;
			return (coord);
		}
		index++;
		vars->x = vars->x + 64;
	}
	return (0);
}

int	ft_freesbee(char **string)
{
	int		i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (0);
}

void	ft_initiation(t_struc *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->s1 = 0;
	vars->s2 = 0;
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"./assets/wall.xpm", &vars->s1, &vars->s2);
	vars->floor = mlx_xpm_file_to_image(vars->mlx,
			"./assets/floor.xpm", &vars->s1, &vars->s2);
	vars->herodown = mlx_xpm_file_to_image(vars->mlx,
			"./assets/herodown.xpm", &vars->s1, &vars->s2);
	vars->heroup = mlx_xpm_file_to_image(vars->mlx,
			"./assets/heroup.xpm", &vars->s1, &vars->s2);
	vars->heroleft = mlx_xpm_file_to_image(vars->mlx,
			"./assets/heroleft.xpm", &vars->s1, &vars->s2);
	vars->heroright = mlx_xpm_file_to_image(vars->mlx,
			"./assets/heroright.xpm", &vars->s1, &vars->s2);
	vars->exit = mlx_xpm_file_to_image(vars->mlx,
			"./assets/exit.xpm", &vars->s1, &vars->s2);
	vars->item = mlx_xpm_file_to_image(vars->mlx,
			"./assets/wine.xpm", &vars->s1, &vars->s2);
	vars->count = 0;
	return ;
}

void	ft_reader(char *map, t_struc *vars)
{
	int		end;
	int		i;

	i = open(map, O_RDONLY);
	end = read(i, vars->readcont, 9999);
	vars->readcont[end] = '\0';
	close(i);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:11:50 by eavilov           #+#    #+#             */
/*   Updated: 2022/04/04 13:25:19 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_format_checker(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '.' && map[i + 1] == 'b'
			&& map[i + 2] == 'e' && map[i + 3] == 'r')
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_struc		vars;
	t_assets	content;

	(void) ac;
	if (!av[1] || ft_format_checker(av[1]) == 0)
	{
		ft_putstr("Error : select a correct map please 🐄\n");
		return (0);
	}
	ft_reader(av[1], &vars);
	if (ft_map_parser(&vars, &content) == 0)
	{
		free(vars.res);
		free(vars.coords);
		return (0);
	}
	vars.coords = ft_fetch_coords(&vars);
	vars.x = vars.coords[0];
	vars.y = vars.coords[1];
	mlx_key_hook(vars.win, mlx_move, &vars);
	mlx_hook(vars.win, 17, 0, ft_mlx_close, &vars);
	free(vars.res);
	free(vars.coords);
	mlx_loop(vars.mlx);
}

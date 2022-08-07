/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:59:23 by eavilov           #+#    #+#             */
/*   Updated: 2022/08/07 10:42:22 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_is_rectangular(char *map, t_struc *vars)
{
	char	**fullmap;
	int		i;

	i = 0;
	fullmap = ft_split(map, '\n');
	vars->res = (int *)malloc(sizeof(int) * 2);
	vars->res[0] = ft_strlen(fullmap[0]);
	vars->res[1] = countchar(map, '\n');
	while (fullmap[i] && fullmap[i + 1])
	{
		if (ft_strlen(fullmap[i]) == ft_strlen(fullmap[i + 1]))
			i++;
		else
		{
			ft_freesbee(fullmap);
			return (0);
		}
	}
	ft_freesbee(fullmap);
	return (1);
}

int	ft_isthere_asset(char *map, t_struc *vars, t_assets *content)
{
	int			i;

	content->item = 0;
	content->player = 0;
	content->exit = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
		{
			vars->itemcount++;
			content->item++;
		}
		else if (map[i] == 'E')
			content->exit++;
		else if (map[i] == 'P')
			content->player++;
		i++;
	}
	if (content->item > 0 && content->exit > 0 && content->player == 1)
		return (1);
	else
		return (0);
}

int	ft_is_closed(char *map)
{
	char	**fullmap;
	int		checker;
	int		lines;
	int		end;

	checker = 0;
	lines = countchar(map, '\n');
	fullmap = ft_split(map, '\n');
	end = ft_strlen(fullmap[0]);
	while (fullmap[0][checker] == '1')
		checker++;
	if (checker != end && checker != ft_strlen(fullmap[lines]))
		return (ft_freesbee(fullmap));
	checker = 0;
	while (fullmap[checker])
	{
		if (fullmap[checker][0] != '1' || fullmap[checker][end - 1] != '1')
			return (ft_freesbee(fullmap));
		checker++;
	}
	ft_freesbee(fullmap);
	return (1);
}

int	ft_map_checker(t_struc *vars, t_assets *content)
{
	if (ft_is_rectangular(vars->readcont, &*vars) == 0)
	{
		ft_putstr("Error : your map is not rectangular\n");
		return (0);
	}
	if (ft_isthere_asset(vars->readcont, &*vars, &*content) == 0)
	{
		if (content->player > 1)
			ft_putstr("Error : you have too many players\n");
		else if (content->player == 0)
			ft_putstr("Error : you have no player\n");
		else if (content->item == 0)
			ft_putstr("Error : your map has no item\n");
		else if (content->exit == 0)
			ft_putstr("Error : your map has no exit point\n");
		return (0);
	}
	if (ft_is_closed(vars->readcont) == 0 || vars->readcont[0] != '1')
	{
		ft_putstr("Error : your map has holes or is weirdly parsed\n");
		return (0);
	}
	return (1);
}

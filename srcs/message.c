/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:59:11 by eavilov           #+#    #+#             */
/*   Updated: 2022/03/30 10:26:15 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_message_builder(void)
{
	char		*result;
	char		*str1;
	char		*nb;
	char		*str2;
	static int	i;

	str1 = "You moved ";
	nb = ft_itoa(++i);
	if (i == 1)
		str2 = " time\n";
	else
		str2 = " times\n";
	result = ft_strtjoin(str1, nb, str2);
	free(nb);
	return (result);
}

void	ft_counter(t_struc *vars)
{
	int			x;
	int			y;
	int			index;
	char		*str;

	x = 0;
	y = 0;
	index = 0;
	while (vars->readcont[index] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x, y);
		x = x + 64;
		index++;
	}
	str = ft_message_builder();
	ft_putstr(str);
	free(str);
}

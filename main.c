#include "so_long.h"

int main(int ac, char **av)
{
	t_struc		vars;
	t_hero		hero;

	(void) ac;
	if (ft_map_parser(av[1], &vars) == 0)
	{
		free(vars.res);
		free(vars.coords);
		return(0);
	}
	vars.coords = ft_fetch_coords(&vars);
	vars.x = vars.coords[0];
	vars.y = vars.coords[1];
	mlx_key_hook(vars.win, mlx_move, &vars);
	free(vars.res);
	free(vars.coords);
	mlx_loop(vars.mlx);
}
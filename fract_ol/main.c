#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


int	handle_exit(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
	return (1);
}

int main(int argc, char *argv[])
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "fractalol");
	mlx_hook(vars.win, 2, 1L<<0, handle_exit, &vars);
	mlx_loop(vars.mlx);
	return 0;
}

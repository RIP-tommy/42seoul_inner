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
	int res;

	if (keycode == 0x35)
		exit(0);
	return (1);
}

int main(int argc, char *argv[])
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "fractalol");
	mlx_key_hook(vars.win, handle_exit, vars.win);
	mlx_loop(vars.mlx);
	return 0;
}

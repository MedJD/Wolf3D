
#include "../include/wolf3d.h"

static void		function_hook(t_raycaster *r)
{
	mlx_hook(r->mlx_pointers[1], 17, 0, close_map, r);
	mlx_hook(r->mlx_pointers[1], 2, 0, keys, r);
	mlx_hook(r->mlx_pointers[1], 6, 0, mouse, r);
	mlx_hook(r->mlx_pointers[1], 4, 0, mouse_press, r);
	mlx_loop(r->mlx_pointers[0]);
}

static void		inisialize_raycaster(t_raycaster *r)
{
	r->map.weidth = 0;
	r->map.height = 0;
	r->map.map = NULL;
	r->player.position = vecset(0.0, 0.0);
	r->player.direction = vecset(0.0, 1.0);
	r->player.plane = vecset(-0.58, 0.0);
	r->player.tmp_plane = 0;
}

static void		initialize_mlx(t_raycaster *r)
{
	r->mlx_pointers[0] = mlx_init();
	r->mlx_pointers[1] = mlx_new_window(r->mlx_pointers[0], WIDTH, HEIGHT,
			"WOLF3D");
	r->mlx_pointers[2] = mlx_new_image(r->mlx_pointers[0], WIDTH, HEIGHT);
	r->image_data[0] = (int *)mlx_get_data_addr(r->mlx_pointers[2],
			&r->mlx_properties[0], &r->mlx_properties[1],
			&r->mlx_properties[2]);
	r->mlx_pointers[3] = mlx_new_image(r->mlx_pointers[0], r->map.weidth *
			5, r->map.height * 5);
	r->image_data[1] = (int *)mlx_get_data_addr(r->mlx_pointers[3],
			&r->mlx_properties[0], &r->mlx_properties[1],
			&r->mlx_properties[2]);
}

static void		ft_perror(int error)
{
	if (error == 0)
		write(1, "error : no passed map file.\n", 28);
	else if (error == 1)
		write(1, "error : cannot open file.\n", 27);
	else if (error == 2)
		write(1, "error : something happened on the way ...\n", 42);
	else if (error == 3)
		write(1, "error : cannot play with this map, you need space\n", 49);
	else
		write(1, "error:something happened when the loading of textures\n", 53);
	exit(0);
}

int				main(int ac, char **av)
{
	int				fd;
	t_raycaster		raycaster;

	if (ac != 2)
		ft_perror(0);
	if ((fd = open(av[1], O_RDONLY)) == -1 || read(fd, &raycaster, 0) < 0)
		ft_perror(1);
	inisialize_raycaster(&raycaster);
	if (parse_map(fd, &raycaster) == -1)
		ft_perror(2);
	if (raycaster.player.position.x == 0.0)
	{
		free(raycaster.map.map);
		ft_perror(3);
	}
	initialize_mlx(&raycaster);
	if (get_texture(&raycaster) == -1)
		ft_perror(4);
	render(&raycaster);
	function_hook(&raycaster);
	return (0);
}

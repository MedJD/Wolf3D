
#include "../include/wolf3d.h"

static void		render_map(t_thread *r)
{
	int			x;
	int			y;

	x = -1;
	while (++x < WIDTH)
	{
		y = (int)(r->i * (HEIGHT / NBTHREAD) - 1);
		ray_constrector(r->r, x);
		hit_loop(r->r);
		wall_constrector(r->r);
		while (++y < (int)((r->i + 1) * (HEIGHT / NBTHREAD)))
			r->r->image_data[0][y * WIDTH + x] = color_picker(r->r, y);
	}
	pthread_exit(NULL);
}

static void		render_minimap(t_raycaster *r)
{
	int			x;
	int			y;

	x = -1;
	while (++x < r->map.weidth * 5)
	{
		y = -1;
		while (++y < r->map.height * 5)
		{
			r->image_data[1][y * r->map.weidth * 5 + x] = 0xAA000000;
			if (r->map.map[(y / 5) * r->map.weidth + (x / 5)] == 0)
				r->image_data[1][y * r->map.weidth * 5 + x] = 0xAAFFFFFF;
			if (x / 5 == (int)r->player.position.x && y / 5 ==
					(int)r->player.position.y)
				r->image_data[1][y * r->map.weidth * 5 + x] = 0xAAFF0000;
		}
	}
}

static void		multi_thrd(t_raycaster *r)
{
	pthread_t	thread[NBTHREAD];
	t_thread	div[NBTHREAD];
	int			i;

	ft_bzero(r->image_data[0], WIDTH * HEIGHT * 4);
	i = -1;
	while (++i < NBTHREAD)
	{
		div[i].r = copy_raycaster(r);
		div[i].i = i;
		pthread_create(&thread[i], NULL, (void *)render_map, &div[i]);
	}
	while (--i >= 0)
		pthread_join(thread[i], NULL);
}

void			render(t_raycaster *r)
{
	multi_thrd(r);
	render_minimap(r);
	mlx_put_image_to_window(r->mlx_pointers[0], r->mlx_pointers[1],
			r->mlx_pointers[2], 0, 0);
	mlx_put_image_to_window(r->mlx_pointers[0], r->mlx_pointers[1],
			r->mlx_pointers[3], 0, 0);
}

int				close_map(t_raycaster *r)
{
	mlx_destroy_image(r->mlx_pointers[0], r->mlx_pointers[3]);
	mlx_destroy_image(r->mlx_pointers[0], r->mlx_pointers[2]);
	mlx_destroy_window(r->mlx_pointers[0], r->mlx_pointers[1]);
	if (r->map.map)
		free(r->map.map);
	exit(0);
}

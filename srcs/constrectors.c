
#include "../include/wolf3d.h"

int				color_picker(t_raycaster *r, int y)
{
	int			color;

	r->texture.index.y = (2 * y + r->wall.height - HEIGHT) *
		r->texture.height[0] / (r->wall.height * 2);
	if (y <= r->wall.min)
		color = 3457259;
	else if (y >= r->wall.max)
		color = 6911610;
	else if (r->wall.side == NORD)
		color = r->texture.image_data[0][(r->texture.weidth[0] *
				r->texture.index.y + r->texture.index.x)];
	else if (r->wall.side == EST)
		color = r->texture.image_data[1][(r->texture.weidth[1] *
				r->texture.index.y + r->texture.index.x)];
	else if (r->wall.side == SUD)
		color = r->texture.image_data[2][(r->texture.weidth[2] *
				r->texture.index.y + r->texture.index.x)];
	else
		color = r->texture.image_data[3][(r->texture.weidth[3] *
				r->texture.index.y + r->texture.index.x)];
	return (color);
}

void			ray_constrector(t_raycaster *r, int x)
{
	double		scalar;

	scalar = 2.0 * x / (double)WIDTH - 1.0;
	r->ray.direction = vecadd(r->player.direction, vecopx(r->player.plane,
				scalar));
	r->curr_position.x = floor(r->player.position.x);
	r->curr_position.y = floor(r->player.position.y);
	r->ray.delta = vecset(fabs(1.0 / r->ray.direction.x), fabs(1.0 /
				r->ray.direction.y));
	r->ray.step.x = (r->ray.direction.x < 0) ? -1 : 1;
	r->ray.step.y = (r->ray.direction.y < 0) ? -1 : 1;
	r->ray.firstdelta.x = r->ray.direction.x < 0 ? (r->player.position.x -
			r->curr_position.x) * r->ray.delta.x : (r->curr_position.x + 1.0 -
				r->player.position.x) * r->ray.delta.x;
	r->ray.firstdelta.y = r->ray.direction.y < 0 ? (r->player.position.y -
			r->curr_position.y) * r->ray.delta.y : (r->curr_position.y + 1.0 -
				r->player.position.y) * r->ray.delta.y;
}

void			wall_constrector(t_raycaster *r)
{
	if (r->wall.side == OUEST || r->wall.side == EST)
	{
		r->wall.distance = (r->curr_position.x - r->player.position.x +
				(1 - r->ray.step.x) / 2) / r->ray.direction.x;
		r->wall.hit = r->player.position.y + r->wall.distance *
			r->ray.direction.y;
	}
	else
	{
		r->wall.distance = (r->curr_position.y - r->player.position.y +
				(1 - r->ray.step.y) / 2) / r->ray.direction.y;
		r->wall.hit = r->player.position.x + r->wall.distance *
			r->ray.direction.x;
	}
	r->wall.hit -= floor(r->wall.hit);
	r->wall.height = (int)(HEIGHT / r->wall.distance);
	r->wall.min = (HEIGHT / 2) - (r->wall.height / 2);
	r->wall.max = (HEIGHT / 2) + (r->wall.height / 2);
	r->texture.index.x = (int)(r->wall.hit * (double)r->texture.weidth[0]);
	if (r->wall.side == OUEST || r->wall.side == SUD)
		r->texture.index.x = r->texture.weidth[0] - r->texture.index.x - 1;
}

t_raycaster		*copy_raycaster(t_raycaster *old)
{
	t_raycaster	*new;

	new = (t_raycaster *)malloc(sizeof(struct s_raycaster));
	new->map = old->map;
	new->player = old->player;
	new->curr_position = old->curr_position;
	new->ray = old->ray;
	new->wall = old->wall;
	new->texture = old->texture;
	new->mlx_pointers[0] = old->mlx_pointers[0];
	new->mlx_pointers[1] = old->mlx_pointers[1];
	new->mlx_pointers[2] = old->mlx_pointers[2];
	new->mlx_pointers[3] = old->mlx_pointers[3];
	new->mlx_properties[0] = old->mlx_properties[0];
	new->mlx_properties[1] = old->mlx_properties[1];
	new->mlx_properties[2] = old->mlx_properties[2];
	new->image_data[0] = old->image_data[0];
	new->image_data[1] = old->image_data[1];
	return (new);
}

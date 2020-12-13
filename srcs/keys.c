
#include "../include/wolf3d.h"

static void		move(t_raycaster *r, t_vec2 next_position)
{
	if (r->map.map[(int)next_position.x + (int)r->player.position.y *
			r->map.weidth] == 0 && next_position.x >= 0.00001 &&
			(int)next_position.x < r->map.weidth)
		r->player.position.x = next_position.x;
	if (r->map.map[(int)r->player.position.x + r->map.weidth *
			(int)next_position.y] == 0 && next_position.y >= 0.00001 &&
			(int)next_position.y < r->map.height)
		r->player.position.y = next_position.y;
}

static void		rot(t_player *player, double angle)
{
	double		tmp_plane;

	tmp_plane = player->direction.x;
	player->direction.x = player->direction.x * cos(angle) -
		player->direction.y * sin(angle);
	player->direction.y = tmp_plane * sin(angle) + player->direction.y
		* cos(angle);
	tmp_plane = player->plane.x;
	player->plane.x = player->plane.x * cos(angle) - player->plane.y
		* sin(angle);
	player->plane.y = tmp_plane * sin(angle) + player->plane.y * cos(angle);
}

int				keys(int key, t_raycaster *r)
{
	t_vec2		next_position;

	if (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == ESC)
	{
		if (key == ESC)
			close_map(r);
		if (key == UP)
		{
			next_position = vecadd(r->player.position,
					vecopx(r->player.direction, 0.2));
			move(r, next_position);
		}
		if (key == DOWN)
		{
			next_position = vecsub(r->player.position,
					vecopx(r->player.direction, 0.2));
			move(r, next_position);
		}
		if (key == RIGHT)
			rot(&r->player, 10.0 * M_PI / 180.0);
		if (key == LEFT)
			rot(&r->player, -10.0 * M_PI / 180.0);
		render(r);
	}
	return (1);
}

int				mouse(int x, int y, t_raycaster *r)
{
	double		angle;

	angle = (double)y;
	if (x < r->player.tmp_plane - 10 || x > r->player.tmp_plane + 10)
	{
		if (x > r->player.tmp_plane)
			angle = 1.0;
		else
			angle = -1.0;
		r->player.tmp_plane = x;
		rot(&r->player, angle * 10.0 * M_PI / 180.0);
		render(r);
	}
	return (1);
}

int				mouse_press(int button, int x, int y, t_raycaster *r)
{
	t_vec2 next_position;

	x = y;
	if (button == 4 || button == 5)
	{
		if (button == 5)
		{
			next_position = vecadd(r->player.position,
					vecopx(r->player.direction, 0.2));
			move(r, next_position);
		}
		else if (button == 4)
		{
			next_position = vecsub(r->player.position,
					vecopx(r->player.direction, 0.2));
			move(r, next_position);
		}
		render(r);
	}
	return (1);
}

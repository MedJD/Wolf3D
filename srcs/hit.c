
#include "../include/wolf3d.h"

static int		check_position(t_raycaster *r)
{
	if (r->curr_position.x >= 0 && r->curr_position.x < r->map.weidth
			&& r->curr_position.y >= 0 && r->curr_position.y < r->map.height)
		return (1);
	return (0);
}

static void		delta_x(t_raycaster *r)
{
	r->ray.firstdelta.x += r->ray.delta.x;
	r->curr_position.x += r->ray.step.x;
	r->wall.side = (int)r->player.position.x < r->curr_position.x ? EST : OUEST;
}

static void		delta_y(t_raycaster *r)
{
	r->ray.firstdelta.y += r->ray.delta.y;
	r->curr_position.y += r->ray.step.y;
	r->wall.side = (int)r->player.position.y < r->curr_position.y ? NORD : SUD;
}

void			hit_loop(t_raycaster *r)
{
	while (check_position(r))
	{
		if (r->ray.firstdelta.x < r->ray.firstdelta.y)
			delta_x(r);
		else
			delta_y(r);
		if (r->map.map[r->curr_position.x + r->map.weidth * r->curr_position.y])
			break ;
	}
}

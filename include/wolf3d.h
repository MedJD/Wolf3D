
#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1500
# define HEIGHT 1500
# define NBTHREAD 4
# define NORD 1
# define EST 2
# define SUD 3
# define OUEST 4
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# include <mlx.h>
# include <pthread.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_map
{
	int			weidth;
	int			height;
	int			*map;
}					t_map;

typedef struct		s_player
{
	t_vec2		position;
	t_vec2		direction;
	t_vec2		plane;
	int			tmp_plane;
}					t_player;

typedef struct		s_texture
{
	void		*content[4];
	int			*image_data[4];
	int			weidth[4];
	int			height[4];
	t_vec2i		index;
}					t_texture;

typedef struct		s_wall
{
	double		side;
	double		distance;
	double		height;
	double		max;
	double		min;
	double		hit;
}					t_wall;

typedef struct		s_ray
{
	t_vec2		direction;
	t_vec2		firstdelta;
	t_vec2		delta;
	t_vec2i		step;
}					t_ray;

typedef struct		s_raycaster
{
	void		*mlx_pointers[4];
	int			mlx_properties[3];
	int			*image_data[2];
	t_map		map;
	t_player	player;
	t_vec2i		curr_position;
	t_ray		ray;
	t_wall		wall;
	t_texture	texture;
}					t_raycaster;

typedef struct		s_thread
{
	int			i;
	t_raycaster	*r;
}					t_thread;

int					parse_map(int fd, t_raycaster *r);
int					get_texture(t_raycaster *r);
void				render(t_raycaster *r);
void				hit_loop(t_raycaster *r);
int					color_picker(t_raycaster *r, int y);
void				ray_constrector(t_raycaster *r, int x);
void				wall_constrector(t_raycaster *r);
t_raycaster			*copy_raycaster(t_raycaster *old);
int					mouse_press(int button, int x, int y, t_raycaster *r);
int					keys(int key, t_raycaster *r);
int					mouse(int x, int y, t_raycaster *r);
int					color_picker(t_raycaster *r, int y);
int					close_map(t_raycaster *r);

#endif

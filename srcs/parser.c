
#include "../include/wolf3d.h"

static void		set_map(t_raycaster *r, char **line_splited, int lenght_line)
{
	int			i;
	int			carre;

	i = -1;
	while (++i < lenght_line)
	{
		carre = ft_atoi(line_splited[i]);
		if (carre == 0 && r->player.position.x == 0.0)
			r->player.position = vecset(i + 0.2, r->map.height + 0.2);
		r->map.map[r->map.height * r->map.weidth + i] = carre;
	}
}

static int		clean_up(char ***line_splited, char **line, int **map, int fd)
{
	int			i;
	char		**tmp;

	i = 0;
	tmp = *line_splited;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i] = 0;
		i++;
	}
	*line ? free(*line) : 0;
	*line = NULL;
	*map ? free(*map) : 0;
	*map = NULL;
	close(fd);
	return (-1);
}

int				parse_map(int fd, t_raycaster *r)
{
	char		*line;
	char		**line_splited;
	int			lenght_line;

	while (get_next_line(fd, &line) > 0)
	{
		line_splited = ft_strsplit(line, ' ');
		lenght_line = line_lenght(line_splited);
		r->map.weidth = (r->map.height == 0) ? lenght_line : r->map.weidth;
		if (ft_isdigit(line) == 0)
			return (clean_up(&line_splited, &line, &r->map.map, fd));
		if (r->map.weidth != lenght_line)
			return (clean_up(&line_splited, &line, &r->map.map, fd));
		if (!(r->map.map = (int*)ft_realloc((void*)(&r->map.map), sizeof(int)
						* r->map.height * r->map.weidth, sizeof(int) *
						(r->map.height + 1) * r->map.weidth)))
			return (clean_up(&line_splited, &line, &r->map.map, fd));
		set_map(r, line_splited, lenght_line);
		free_double_pointer(&line_splited);
		free(line);
		r->map.height++;
	}
	close(fd);
	return (0);
}

static int		set_texture(t_raycaster *r)
{
	int			i;

	i = -1;
	while (++i < 4)
		if (r->texture.weidth[i] != 64 || r->texture.height[i] != 64)
			return (-1);
	while (--i >= 0)
		r->texture.image_data[i] = (int *)mlx_get_data_addr(
				r->texture.content[i], &r->mlx_properties[0],
				&r->mlx_properties[1], &r->mlx_properties[2]);
	return (1);
}

int				get_texture(t_raycaster *r)
{
	r->texture.content[0] = mlx_xpm_file_to_image(r->mlx_pointers[0],
			"./textures/texture_nord", &r->texture.weidth[0],
			&r->texture.height[0]);
	r->texture.content[1] = mlx_xpm_file_to_image(r->mlx_pointers[0],
			"./textures/texture_est", &r->texture.weidth[1],
			&r->texture.height[1]);
	r->texture.content[2] = mlx_xpm_file_to_image(r->mlx_pointers[0],
			"./textures/texture_sud", &r->texture.weidth[2],
			&r->texture.height[2]);
	r->texture.content[3] = mlx_xpm_file_to_image(r->mlx_pointers[0],
			"./textures/texture_ouest", &r->texture.weidth[3],
			&r->texture.height[3]);
	return (set_texture(r));
}

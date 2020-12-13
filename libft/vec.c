
#include "libft.h"

t_vec2		vecset(double x, double y)
{
	t_vec2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vec2		vecadd(t_vec2 a, t_vec2 b)
{
	t_vec2	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	return (v);
}

t_vec2		vecsub(t_vec2 a, t_vec2 b)
{
	t_vec2	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	return (v);
}

t_vec2		vecopx(t_vec2 a, double x)
{
	t_vec2	v;

	v.x = a.x * x;
	v.y = a.y * x;
	return (v);
}

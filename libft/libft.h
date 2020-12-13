
#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vec2
{
	double			x;
	double			y;
}					t_vec2;

typedef struct		s_vec2i
{
	int				x;
	int				y;
}					t_vec2i;

int					ft_isdigit(char *line);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
int					ft_nbr_words(char const *str, char c);
int					ft_word_size(char const *str, char c, int k);
int					get_next_line(int fd, char **line);
int					line_lenght(char **line);
void				free_double_pointer(char ***split);
void				*ft_realloc(void **ptr, size_t old, size_t len);
t_vec2				vecset(double x, double y);
t_vec2				vecadd(t_vec2 a, t_vec2 b);
t_vec2				vecsub(t_vec2 a, t_vec2 b);
t_vec2				vecopx(t_vec2 a, double x);

#endif

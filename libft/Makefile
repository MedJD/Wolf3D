NAME	= libft.a

SRC		= get_next_line.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_strdup.c \
		  ft_strcpy.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_atoi.c \
		  ft_strsplit.c \
		  ft_strjoin.c \
		  ft_strsub.c \
		  ft_strnew.c \
		  ft_word_size.c \
		  ft_nbr_words.c \
		  vec.c \
		  tools.c \
		  ft_realloc.c \
		  ft_isdigit.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $< -I .

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
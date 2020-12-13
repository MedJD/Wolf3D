NAME	= wolf3d

SRCS = srcs/constrectors.c \
	   srcs/keys.c \
	   srcs/parser.c \
	   srcs/hit.c \
	   srcs/main.c \
	   srcs/rendrer.c

SRC = $(SRCS:%=./srcs/%)
OBJ = $(SRCS:.c=.o)


INCLUDES = ./minilibx_macos
CFLAGS = -Wall -Wextra -Werror
MLX = ./minilibx -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/ -lft
THREAD = . -lpthread
MYFLAG =  -I $(INCLUDES) -L $(MLX) -L $(LIBFT) -L $(THREAD)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $^ $(MYFLAG)

%.o: ./srcs/%.c
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
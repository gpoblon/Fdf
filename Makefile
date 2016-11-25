NAME	=	fdf

SRC		=	main.c \
			input_to_map.c \
			draw_map.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
# CFLAGS	=	-Werror -Wextra -Wall

LIBLINK	=	-L./libft -lft
MLX		=	./minilibx/mlx.a
MLXLINK	=	-L./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft
		$(CC) $(LIBLINK) $(MLXLINK) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)
		make -C ./libft clean
		rm -f ./minilibx/$(OBJ)

fclean:	clean
		rm -rf $(NAME)
		make -C ./libft fclean
		rm -f ./minilibx/$(NAME)

re:		fclean all

.PHONY: clean

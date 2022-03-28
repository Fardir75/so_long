NAME 	= so_long
SRCS	= ./main.c ./misc.c ./lib1.c ./lib2.c ./mapchecker.c ./message.c ./movement.c ./parser.c ./placers.c
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f
MLX		= -I ./minilibx_opengl_20191021/ -framework OpenGL -framework AppKit
SAN		= -fsanitize=address -g3

$(NAME): 
	gcc $(MLX) $(SRCS) libmlx.a -o $(NAME) Libft.a

all: ${NAME}

clean:
	${RM}

san: re
	gcc $(MLX) $(SAN) $(SRCS) libmlx.a -o $(NAME)

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: re all fclean clean
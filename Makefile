NAME 	= so_long
SRCS	= ./main.c ./srcs/misc.c ./srcs/lib1.c ./srcs/lib2.c ./srcs/mapchecker.c ./srcs/message.c ./srcs/movement.c ./srcs/parser.c ./srcs/placers.c ./srcs/transition.c
OBJS	= $(SRCS:.c=.o)
MLX		= -I ./minilibx_opengl_20191021/ -framework OpenGL -framework AppKit
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f
LIBMLX 	= ./minilibx_opengl_20191021/libmlx.a

$(NAME):	$(OBJS)
	$(MAKE) -C ./minilibx_opengl_20191021/
	gcc $(CFLAGS) $(MLX) $(SRCS) $(LIBMLX) -o $(NAME)

all: ${NAME}

clean:
	${RM} $(OBJS) $(LIBMLX)

norm: 
	norminette $(SRCS) so_long.h

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: re all fclean clean
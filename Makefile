CC = cc

NAME = cub3d

SRCS = 	main.c \
		draw_buffer.c \
		execution_main.c \
		fill_buffer.c \
		fill_buffer_util_1.c \
		fill_buffer_util_2.c \
		init_structs.c \
		init_structs_util_1.c \
		init_structs_util_2.c \
		key_press.c \
		key_rotation.c \
		floor_and_ceiling.c \
		texture_calc_util.c \
		check_texture_path.c \
		parsing1.c \
		parsing2.c \
		parsing3.c \
		parsing4.c \
		parsing5.c \
		queue1.c \
		queue2.c


OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS =  -L./minilibx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

LIBFTA = ./libft/libft.a
MLXA = ./minilibx/libmlx.a

$(NAME) : $(OBJS)
	$(MAKE) bonus -C ./libft
	$(MAKE) -C ./minilibx
	$(CC) $(CFLAGS) ${LIBFTA} ${MLXA} $(MLXFLAGS) $^ -o ${NAME}

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f ${OBJS}
	rm -f ${B_OBJS}
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx clean

fclean : clean
	rm -f ${NAME}
	rm -f ${B_NAME}
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx clean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all
.PHONY : clean
.PHONY : fclean
.PHONY : re

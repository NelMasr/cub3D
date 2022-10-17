NAME	=	cub3D

SRCS	=	cub3d.c \
			engine/controller.c \
			engine/end_game.c \
			engine/engine_utils.c \
			engine/player.c \
			engine/raycasting.c \
			engine/sprites.c \
			engine/sprites_init.c \
			engine/textures.c \
			parsing/check_data.c \
			parsing/parse_map.c \
			parsing/parse_resolution_and_colors.c \
			parsing/parse_textures.c \
			utils/error.c \
			utils/ft_split.c \
			utils/get_next_line.c \
			utils/get_next_line_utils.c \
			utils/init2.c \
			utils/init.c \
			utils/libft.c \
			utils/save.c \
			utils/utils.c \
			utils/verif.c \

OBJS	=	${SRCS:.c=.o}

# COLORS
C_NO    =   "\033[00m"
C_OK    =   "\033[36m"
C_GOOD  =   "\033[32m"
C_ERROR =   "\033[31m"
C_WARN  =   "\033[33m"

# DBG MESSAGE
SUCCESS =   $(C_GOOD)SUCCESS !$(C_OK)
OK      =   $(C_OK)OK$(C_NO)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

MLX_DIR =	minilibx-linux

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:
			@$(MAKE) -j $(NAME)

$(NAME): $(OBJS)
			@${CC} $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
			@echo "Creating  [$(NAME)]" $(SUCCESS)

clean:
			@rm -rf $(OBJS)
			@echo "Cleaning all the .o mess..." $(OK)

fclean:		clean
			@rm -rf $(NAME)
			@echo "Deleting [$(NAME)]" $(OK)

re:			fclean all

.PHONY:		all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 02:20:07 by grebrune          #+#    #+#              #
#    Updated: 2024/09/30 17:03:22 by beroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################################################################################################
#                                                       VARIABLES                                                      #
########################################################################################################################

PARS		:=	main.c					\
				check_file.c			\
				clear_error.c			\
				cub_utils.c				\
				cub_utils_2.c			\
				cub_color.c				\
				cub_map_getter.c		\
				cub_map_checker.c		\
				cub_texture.c			\
				get_next_line.c			\
				get_next_line_utils.c	\
				setter_getter.c

EXEC		:=	cub3d.c					\
				signal.c				\
				raycaster.c				\
				raycaster_utils.c		\
				render.c				\
				img_gen.c				\
				move.c					\
				move_utils.c			\
				texture.c				\
				minimap.c

PARS_D		:=	sources/parsing/

EXEC_D		:=	sources/executable/

OBJS_D		:=	objects/

OBJS		:=	$(addprefix $(OBJS_D), $(PARS:.c=.o)) $(addprefix $(OBJS_D), $(EXEC:.c=.o))

HEAD_D		:=	includes/

HEAD		:=	cub3d.h

GET			:=	$(HEAD_D)get_next_line.h

CFLAGS		:=	-Wall -Wextra -Werror -g3 -O3

BIN			:=	cub3D

########################################################################################################################
#                                                         MLX                                                          #
########################################################################################################################

MLX			:=	libmlx.a

MLX_D		:=	mlx_linux/

MLX_F		:=	-L$(MLX_D) -L/usr/lib -lmlx -lXext -lX11 -lm -lz

MLX_H		:=	$(MLX_D)mlx.h

MLX_A		:=	$(addprefix $(MLX_D), $(MLX))

########################################################################################################################
#                                                        RULES                                                         #
########################################################################################################################

all			:	lib
				$(MAKE) $(BIN)

lib			:
				$(MAKE) -C $(MLX_D)

$(BIN)		:	$(OBJS_D) $(OBJS) $(MLX_A) Makefile
				$(CC) $(CFLAGS) -o $(BIN) $(OBJS) $(MLX_A) $(MLX_F)

$(OBJS_D)%.o: $(PARS_D)%.c $(HEAD_D)$(HEAD) $(MLX_H) $(GET)
				$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)%.o: $(EXEC_D)%.c $(HEAD_D)$(HEAD) $(MLX_H)
				$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

clean		:
				$(RM) -r $(OBJS) $(OBJS_D)
				$(MAKE) clean -C mlx_linux

fclean		:	clean
				$(RM) $(BIN)
				$(MAKE) clean -C mlx_linux


re			:	fclean all

.PHONY: all clean fclean re lib

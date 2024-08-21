# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 02:20:07 by grebrune          #+#    #+#              #
#    Updated: 2024/08/09 15:36:36 by grebrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################################################################################################
#                                                       VARIABLE                                                       #
########################################################################################################################

SRCS		:=	main.c					\
				check_file.c			\
				clear_error.c			\
				cub_utils.c				\
				cub_color.c				\
				cub_map.c				\
				cub_texture.c			\
				get_next_line.c			\
				get_next_line_utils.c	\
				setter_getter.c			\

SRCS_D		:=	sources/

OBJS_D		:=	objects/

OBJS		=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD		:=	cub3d.h			\

HEAD_D		:=	includes/

CFLAGS		:=	cc -Wall -Wextra -Werror -g3

BIN			:=	Moonf

########################################################################################################################
#                                                        RULES                                                         #
########################################################################################################################

all			:	$(BIN)

$(BIN)		:	$(OBJS_D) $(OBJS)
				$(CFLAGS) -o $(BIN) $(OBJS)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)/*.h Makefile
				$(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)
########################################################################################################################
#                                                        COMMANDS                                                      #
########################################################################################################################

clean		:
				$(RM) -r $(OBJS) $(OBJS_D)

fclean		:	clean
				$(RM) $(BIN)

re			:	fclean all

.PHONY: all clean fclean re

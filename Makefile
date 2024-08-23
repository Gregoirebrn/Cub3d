# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 02:20:07 by grebrune          #+#    #+#              #
#    Updated: 2024/08/23 20:47:37 by grebrune         ###   ########.fr        #
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
				get_next_line_utils.c

EXEC		:=	setter_getter.c

PARS_D		:=	sources/parsing/

EXEC_D		:=	sources/executable/

OBJS_D		:=	objects/

OBJS		:=	$(addprefix $(OBJS_D), $(PARS:.c=.o)) $(addprefix $(OBJS_D), $(EXEC:.c=.o))

HEAD_D		:=	includes/

HEAD		:=	cub3d.h

CFLAGS		:=	-Wall -Wextra -Werror -g3

BIN			:=	Moonf

########################################################################################################################
#                                                        RULES                                                         #
########################################################################################################################

all			:	$(BIN)

$(BIN)		:	$(OBJS_D) $(OBJS)
				$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

$(OBJS_D)%.o: $(PARS_D)%.c $(HEAD_D)$(HEAD)
				$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)%.o: $(EXEC_D)%.c $(HEAD_D)$(HEAD)
				$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

clean		:
				$(RM) -r $(OBJS) $(OBJS_D)

fclean		:	clean
				$(RM) $(BIN)

re			:	fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 14:47:45 by tmilcent          #+#    #+#              #
#    Updated: 2023/09/21 12:07:07 by tmilcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

GCC = gcc -Wall -Werror -Wextra -g -fsanitize=address

SRCS = 	src/main.c \
		src/parsing/arg_handler.c \
		src/parsing/textures.c \
		src/parsing/colors.c \

OBJS = $(SRCS:.c=.o)

INC = inc/
INCFT = libft/

LIBFT = $(addprefix $(INCFT), libft.a)

all: $(NAME)

%.o: %.c
	@cd minilibx-linux; ./configure;
	@$(GCC) -I $(INC) -Iminilibx-linux -I $(INCFT) -O3 -c $< -o $@


$(NAME): $(OBJS) $(LIBFT)
	@$(GCC) $(OBJS) -Llibft -lft -Ift -Lminilibx-linux -lmlx_Linux -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	@make a -C $(INCFT)

clean:
	@rm -f $(OBJS)
	@make clean -C $(INCFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(INCFT)

re: fclean all

a: all clean

.PHONY: all clean fclean re a
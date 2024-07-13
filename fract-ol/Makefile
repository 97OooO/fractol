# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:42:06 by osslakri          #+#    #+#              #
#    Updated: 2024/06/13 12:00:47 by osslakri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus

SRC = fractol_init.c fractol_maker.c main.c utils.c manage_events.c mandelbrot.c julia.c asc_dbl.c

SRC_BONUS = bonus/fractol_init_bonus.c\
			bonus/fractol_maker_bonus.c\
			bonus/julia_bonus.c\
			bonus/main_bonus.c\
			bonus/manage_events_bonus.c\
			bonus/mandelbrot_bonus.c\
			bonus/utils_bonus.c\
			bonus/asc_dbl.c\
			bonus/burningship_bonus.c

OBJ=$(SRC:.c=.o)
OBJ_BONUS=$(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ): %.o: %.c fractol.h
	cc -Wall -Wextra -Werror -c $< -o $@
	
bonus: $(OBJ_BONUS)
	cc $(OBJ_BONUS) -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

$(OBJ_BONUS): %.o: %.c bonus/fractol_bonus.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) fractol_bonus

re: fclean all

.PHONY: clean fclean re
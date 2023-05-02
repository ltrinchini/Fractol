# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:59:40 by ltrinchi          #+#    #+#              #
#    Updated: 2022/03/05 11:12:37 by ltrinchi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus

SRCS_WITHOUT_PATH = fractol.c \
					mlx.c \
					zoom.c \
					draw.c \
					mandelbrot.c \
					julia.c \
					error.c \
					colors.c \
					init.c \
					free.c

SRCS_WITHOUT_PATH_BONUS =	fractol_bonus.c \
							mlx_bonus.c \
							move_bonus.c \
							zoom_bonus.c \
							tricorn_bonus.c \
							burningship_bonus.c \
							error_bonus.c \
							init_bonus.c \
							mandelbrot.c \
							draw.c \
							julia.c \
							colors.c \
							free.c

OBJS_WITHOUT_PATH = $(SRCS_WITHOUT_PATH:.c=.o)
OBJS_WITHOUT_PATH_BONUS = $(SRCS_WITHOUT_PATH_BONUS:.c=.o)
HEADER_WITHOUT_PATH = fractol.h
HEADER_WITHOUT_PATH_BONUS = fractol_bonus.h

PATH_TO_SRCS = ./srcs/
PATH_TO_OBJS = ./objs/
PATH_TO_HEADER = ./inclds/

SRCS = $(addprefix $(PATH_TO_SRCS), $(SRCS_WITHOUT_PATH))
OBJS = $(addprefix $(PATH_TO_OBJS), $(OBJS_WITHOUT_PATH))
SRCS_BONUS = $(addprefix $(PATH_TO_SRCS), $(SRCS_WITHOUT_PATH_BONUS))
OBJS_BONUS = $(addprefix $(PATH_TO_OBJS), $(OBJS_WITHOUT_PATH_BONUS))

HEADER = $(addprefix $(PATH_TO_HEADER), $(HEADER_WITHOUT_PATH))
HEADER_BONUS = $(addprefix $(PATH_TO_HEADER), $(HEADER_WITHOUT_PATH_BONUS))

	##### COMMANDS ######
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
CFLAGS_MLX = -framework OpenGL -framework AppKit
RM = rm -rf
	#####################

	########### RESOURCES ###########

	###### LIBFT ######
PATH_TO_LIBFT = ./libft/
LIBFT_A = $(PATH_TO_LIBFT)libft.a
	###################

	###### MLX ######
PATH_TO_MLX = ./minilibx/
LIBMLX_A = $(PATH_TO_MLX)libmlx.a
	#################

	#################################

	###### COLORS FOR PRINTF ######
GREEN 		= \033[0;32m
RED			= \033[0;91m
YELLOW      = \033[0;93m
WHITE       = \033[1;49;97m
	###############################

all: rsc $(PATH_TO_OBJS) $(NAME)
	printf "$(GREEN)✅ $(NAME) is up to date$(WHITE) 👏\n"  

$(PATH_TO_OBJS):
	mkdir -p ./objs/

rsc:
	make -C $(PATH_TO_LIBFT)
	make -C $(PATH_TO_MLX)

$(PATH_TO_OBJS)%.o: $(PATH_TO_SRCS)%.c Makefile $(HEADER) $(HEADER_BONUS) $(LIBFT_A) $(LIBMLX_A)
	printf "\033[2K\r$(YELLOW)⏳ Compiling:$(WHITE) $< 🤞"  
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LIBMLX_A) $(CFLAGS_MLX) -o $(NAME)
	printf "\n$(GREEN)✅ $(NAME) has been build 👍$(WHITE)\n"  

git: fclean
	git add *
	git add -u
	git commit 

clean:
	make clean -C $(PATH_TO_LIBFT)
	make clean -C $(PATH_TO_MLX)
	$(RM) $(PATH_TO_OBJS)
	printf "$(RED)👌 Files has been deleted in $(PATH_TO_OBJS) ($(NAME))$(WHITE)\n"  
	printf "$(GREEN)✅ Clean 👍$(WHITE)\n"  

fclean: clean
	$(RM) $(LIBFT_A)
	$(RM) $(LIBMLX_A)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	printf "$(RED)👌 libft.a has been deleted$(WHITE)\n"  
	printf "$(RED)👌 $(NAME) has been deleted$(WHITE)\n"  
	printf "$(GREEN)✅ Fclean 👍\033$(WHITE)\n"

re: fclean all

bonus: rsc $(PATH_TO_OBJS) $(NAME_BONUS)
	printf "$(GREEN)✅ $(NAME_BONUS) is up to date$(WHITE) 👏\n"  

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_A) $(LIBMLX_A) $(CFLAGS_MLX) -o $(NAME_BONUS)
	printf "\n$(GREEN)✅ $(NAME_BONUS) has been build 👍$(WHITE)\n"  

.PHONY: all rsc debug clean git fclean re bonus
.SILENT:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 13:08:16 by albmarqu          #+#    #+#              #
#    Updated: 2025/07/22 15:03:41 by albmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME = cub3d

#Compile
CC = clang

#Flags
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

#MLX
MLX_PATH = include/lib/MLX42/build
MLX_LIB = $(MLX_PATH)/libmlx42.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

#LIBFT
LIBFT_PATH = include/lib/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

#Clean
CLEAN = rm -Rf

#Sources
SRC = 	main.c \
		parse/parse_args.c \
		parse/parse_info.c \
		parse/parse_textures.c \
		parse/parse_colors.c \
		parse/parse_map.c \
		parse/parse_player.c \
		parse/errors.c \
		parse/utils.c
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))

#Objects
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

#Libraries
LIBS = -L$(MLX_PATH) -lXext -lX11 -lm #-lmlx 

#Headers
HEADERS	= -I ./include -I $(MLX_PATH) -I $(LIBFT_PATH)

#Colors
COLOR_INFO = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_RESET = \033[0m
COLOR_PROGRESS = \033[1;35m
COLOR_HEADER = \033[1;35m

# Progress bar variables
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0
BAR_LENGTH := 30

# Header art
define HEADER_ART
$(COLOR_HEADER)
   ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ 
  ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗
  ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║
  ██║     ██║   ██║██╔══██╗ ╚═══██║██║  ██║
  ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝
   ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ 
$(COLOR_RESET)
endef
export HEADER_ART

all: header $(MLX_LIB) $(LIBFT_LIB) $(NAME)

header:
	@echo "$$HEADER_ART"

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	@printf "\n$(COLOR_SUCCESS)Compiling executable...$(COLOR_RESET)\n"
	@$(CC) $(OBJS) $(HEADERS) $(LIBS) $(CFLAGS) $(LIBFT_FLAGS) -o $(NAME) 
	@printf "$(COLOR_SUCCESS)✅ $(NAME) is ready!$(COLOR_RESET)\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@$(eval PROGRESS=$(shell echo $$(($(CURRENT_FILE)*$(BAR_LENGTH)/$(TOTAL_FILES)))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_FILE)*100/$(TOTAL_FILES)))))
	@printf "\r$(COLOR_INFO)Compiling: [$(COLOR_PROGRESS)"
	@for i in $$(seq 1 $(PROGRESS)); do printf "█"; done
	@for i in $$(seq 1 $$(($(BAR_LENGTH)-$(PROGRESS)))); do printf " "; done
	@printf "$(COLOR_INFO)] %3d%%$(COLOR_RESET)" $(PERCENT)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) 

$(MLX_LIB):
	@printf "$(COLOR_INFO)Compiling MLX library...$(COLOR_RESET)\n"
	@make -C $(MLX_PATH) all > /dev/null 2>&1
	@printf "$(COLOR_SUCCESS)✅ MLX library compiled!$(COLOR_RESET)\n"

$(LIBFT_LIB):
	@printf "$(COLOR_INFO)Compiling libft library...$(COLOR_RESET)\n"
	@make -C $(LIBFT_PATH) all > /dev/null 2>&1
	@printf "$(COLOR_SUCCESS)✅ Libft library compiled!$(COLOR_RESET)\n"

clean:
	@printf "$(COLOR_INFO)Cleaning object files...$(COLOR_RESET)"
	@$(CLEAN) $(OBJS_DIR)
	@printf "\r$(COLOR_SUCCESS)✅ Object files cleaned successfully!$(COLOR_RESET)\n"

fclean: clean
	@printf "$(COLOR_INFO)Deleting $(NAME)...$(COLOR_RESET)"
	@$(CLEAN) $(NAME)
	@printf "\r$(COLOR_SUCCESS)✅ $(NAME) deleted successfully!$(COLOR_RESET)\n"
	@printf "$(COLOR_INFO)Cleaning MLX library...$(COLOR_RESET)\n"
	@make -C $(MLX_PATH) clean > /dev/null 2>&1
	@printf "$(COLOR_SUCCESS)✅ MLX library cleaned!$(COLOR_RESET)\n"
	@printf "$(COLOR_INFO)Cleaning libft library...$(COLOR_RESET)\n"
	@make -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@printf "$(COLOR_SUCCESS)✅ Libft library cleaned!$(COLOR_RESET)\n"

re: fclean all

.PHONY: all clean fclean re header
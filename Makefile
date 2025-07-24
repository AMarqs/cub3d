#Name
NAME = cub3d

#Compile
CC = cc

#Flags
CFLAGS = -Wall -Wextra -Werror -g

#Clean
CLEAN = rm -Rf

#Sources
SRC = 	main.c \
    	init/init.c \
    	init/init_utils.c \
    	elements/elements.c \
    	input/input.c \
    	raycasting/raycasting.c \
    	raycasting/raycasting_utils.c \
    	render/render.c \
    	render/textures.c \
    	utils/utils.c \
		utils/mlx_utils.c \
    	utils/maps_utils.c

#Directories
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))

#Objects
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

#Libraries
MLX_DIR = include/lib/MLX42/libmlx42.a
MLX = $(MLX_DIR)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#Headers
HEADERS	= -I ./include -I $(LIBFT_DIR) -I include/lib/MLX42/include

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

all: header $(NAME)

header:
	@echo "$$HEADER_ART"

$(NAME): $(OBJS) $(MLX)
	@printf "\n$(COLOR_SUCCESS)Compiling executable...$(COLOR_RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -ldl -lm -o $(NAME) 
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

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C include/lib/MLX42

clean:
	@printf "$(COLOR_INFO)Cleaning object files...$(COLOR_RESET)"
	@$(CLEAN) $(OBJS_DIR)
	@printf "\r$(COLOR_SUCCESS)✅ Object files cleaned successfully!$(COLOR_RESET)\n"

fclean: clean
	@printf "$(COLOR_INFO)Deleting $(NAME)...$(COLOR_RESET)"
	@$(CLEAN) $(NAME)
	@printf "\r$(COLOR_SUCCESS)✅ $(NAME) deleted successfully!$(COLOR_RESET)\n"
	@make -C include/lib/MLX42 clean

re: fclean all

.PHONY: all clean fclean re header

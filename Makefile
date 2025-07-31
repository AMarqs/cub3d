#Name
NAME = cub3d

#Compile
CC = clang

#Flags
CFLAGS = -Wall -Wextra -Werror -g

#MLX
MLX_PATH = include/lib/MLX42
MLX_BUILD_PATH = $(MLX_PATH)/build
MLX_LIB = $(MLX_BUILD_PATH)/libmlx42.a
MLX_FLAGS = -L$(MLX_BUILD_PATH) -lmlx42 -ldl -lglfw -pthread -lm

#LIBFT
LIBFT_PATH = include/lib/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

#Clean
CLEAN = rm -Rf

#Sources
SRC =	main.c \
		errors.c \
		parse/parse_args.c \
		parse/parse_info.c \
		parse/parse_floor.c \
		parse/parse_textures.c \
		parse/parse_colors.c \
		parse/parse_map.c \
		parse/parse_counter.c \
		parse/parse_player.c \
		init/init.c \
		exec/hook/key_hook.c \
		exec/input/input_utils.c \
		exec/input/input.c \
		exec/raycasting/raycasting_utils.c \
		exec/raycasting/raycasting.c \
		exec/render/render.c \
		exec/texture/texture.c

SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))

#Objects
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))

#Libraries
LIBS = $(MLX_LIB) -ldl -lglfw -pthread -lm $(LIBFT_FLAGS) 

#Headers
HEADERS	= -I ./include -I $(MLX_PATH)/include -I $(LIBFT_PATH)

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
	@if [ ! -d "$(MLX_BUILD_PATH)" ]; then \
		cmake -B $(MLX_BUILD_PATH) -S $(MLX_PATH) > /dev/null 2>&1; \
	fi
	@cmake --build $(MLX_BUILD_PATH) -j4 > /dev/null 2>&1
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
	clear
	@printf "$(COLOR_INFO)Deleting $(NAME)...$(COLOR_RESET)"
	@$(CLEAN) $(NAME)
	@printf "\r$(COLOR_SUCCESS)✅ $(NAME) deleted successfully!$(COLOR_RESET)\n"
	@printf "$(COLOR_INFO)Cleaning MLX library...$(COLOR_RESET)\n"
	@if [ -d "$(MLX_BUILD_PATH)" ]; then \
		$(CLEAN) $(MLX_BUILD_PATH); \
	fi
	@printf "$(COLOR_SUCCESS)✅ MLX library cleaned!$(COLOR_RESET)\n"
	@printf "$(COLOR_INFO)Cleaning libft library...$(COLOR_RESET)\n"
	@make -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@printf "$(COLOR_SUCCESS)✅ Libft library cleaned!$(COLOR_RESET)\n"

re: fclean all

.PHONY: all clean fclean re header

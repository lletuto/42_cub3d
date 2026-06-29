NAME = cub3D
BNS_NAME = cub3D_bonus

# Dossiers
INCL_BNS = Bonus/Incl
PARS_BNS_DIR = Bonus/Src_Bonus/parsing
EXE_BNS_DIR = Bonus/Src_Bonus/executing
LIBFT_DIR = Incl/libft2
PARSING_DIR = Src/parsing
EXECUTING_DIR = Src/executing
OBJ_DIR = Executable
OBJ_BNS_DIR = Executable/bonus
INCL_DIR = Incl
MINILIBX_DIR = minilibx-linux
MLX_REPO = https://github.com/42paris/minilibx-linux.git

# Commandes
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

# Libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR) -lft
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# Includes
INC = -I$(LIBFT_DIR) -I$(INCL_DIR) -I$(MINILIBX_DIR)
INC_BNS = -I$(LIBFT_DIR) -I$(INCL_BNS) -I$(MINILIBX_DIR)

# Sources MANDATORY
PARS_SRCS = main.c file_check.c free_exit.c struct_init.c paths_colors.c \
	map_reading.c saving_file.c starting_parsing.c utils.c color_check.c
EXEC_SRCS = starting_executing.c moving.c drawing.c game.c dda.c \
	drawing_tex.c utils.c

# Sources BONUS
PARS_BNS_SRCS = main.c file_check.c free_exit.c struct_init.c paths_colors.c \
	map_reading.c saving_file.c starting_parsing.c utils.c color_check.c
EXE_BNS_SRCS = starting_executing.c mini_map.c moving.c drawing.c game.c dda.c \
	drawing_tex.c utils.c

# Génération des chemins complets MANDATORY
PARSING_SRCS = $(addprefix $(PARSING_DIR)/, $(PARS_SRCS))
EXECUTING_SRCS = $(addprefix $(EXECUTING_DIR)/, $(EXEC_SRCS))
SRCS = $(PARSING_SRCS) $(EXECUTING_SRCS)

# Génération des chemins complets BONUS
PARSING_BNS_SRCS = $(addprefix $(PARS_BNS_DIR)/, $(PARS_BNS_SRCS))
EXECUTING_BNS_SRCS = $(addprefix $(EXE_BNS_DIR)/, $(EXE_BNS_SRCS))
SRCS_BNS = $(PARSING_BNS_SRCS) $(EXECUTING_BNS_SRCS)

# Objets
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BNS = $(SRCS_BNS:%.c=$(OBJ_BNS_DIR)/%.o)

SILENT = @

# Couleurs
GREEN = \033[1;38;5;82m
YELLOW = \033[1;38;5;226m
BLUE = \033[1;38;5;39m
RESET = \033[1;0m

# Default rule
all: $(MINILIBX) $(LIBFT) $(NAME)

# Télécharge MinilibX
$(MINILIBX_DIR):
	@echo "$(GREEN)📦 Cloning MinilibX...$(RESET)"
	@git clone $(MLX_REPO) $(MINILIBX_DIR)

# Compile MinilibX
$(MINILIBX): | $(MINILIBX_DIR)
	@echo "$(GREEN)🔨 Building MinilibX...$(RESET)"
	@$(MAKE) -C $(MINILIBX_DIR)

# Create obj folders
$(OBJ_DIR):
	$(SILENT)mkdir -p $(OBJ_DIR)

$(OBJ_BNS_DIR):
	$(SILENT)mkdir -p $(OBJ_BNS_DIR)

# Build executable MANDATORY
$(NAME): $(OBJS)
	$(SILENT)$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"
	@echo "$(BLUE)📁 Using header: $(INCL_DIR)/cube.h$(RESET)"

# Compilation des .o MANDATORY
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(SILENT)$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "compilé : $<"

# Build executable BONUS
$(BNS_NAME): $(OBJS_BNS)
	$(SILENT)$(CC) $(CFLAGS) $(OBJS_BNS) $(LIBS) $(MLXFLAGS) -o $(BNS_NAME)
	@echo "$(YELLOW)✅ $(BNS_NAME) compiled successfully!$(RESET)"
	@echo "$(BLUE)📁 Using header: $(INCL_BNS)/cube.h$(RESET)"

# Compilation des .o BONUS
$(OBJ_BNS_DIR)/%.o: %.c | $(OBJ_BNS_DIR)
	@mkdir -p $(dir $@)
	$(SILENT)$(CC) $(CFLAGS) $(INC_BNS) -c $< -o $@
	@echo "compilé (bonus) : $<"

# Libft
$(LIBFT):
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) > /dev/null

# Règle bonus
bonus: $(MINILIBX) $(LIBFT) $(BNS_NAME)

# Cleaning
clean:
	$(SILENT)rm -rf $(OBJ_DIR)
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) clean > /dev/null || true
	@echo "$(GREEN)🧹 Object files cleaned!$(RESET)"

fclean: clean
	$(SILENT)rm -rf $(MINILIBX_DIR)
	$(SILENT)rm -f $(NAME) $(BNS_NAME)
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null || true
	@echo "$(GREEN)🗑️ All generated files cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
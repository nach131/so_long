# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ NAMES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

NAME		= so_long

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ COLORS ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

GREEN		=\033[0;32m
BLUE 		=\033[0;34m
ORANGE	=\033[38;5;214m
RED			=\033[0;31m
YELLOW	=\033[0;33m
WHITE		=\033[0;37m

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ COMPILATE ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

CC			= gcc
AR 			= ar -rcs
RM			= rm -rf
MKDIR		= -mkdir -p
CFLAGS	= -Wall -Wextra -Werror -g3
MLXFLAGS = -framework OpenGL -framework AppKit

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ DIRECTORIES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

LIBFT_DIR = libft/
LIBMLX_DIR	= mlx/
INCLUDES 	= inc/
SRC_DIR 	= src/
OBJ_DIR 	= obj/
UTILS_DIR	= utils/

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ SOURCES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

LIBSFT = $(LIBFT_DIR)libft.a

MAIN_FILES	=	main
UTILS_FILES	= errors render_map load_img ctrl_map reload player ctrl_move \
			  ctrl_path header

SRC_MAIN_FILES	+=$(MAIN_FILES)
SRC_UTILS_FILES	+=$(addprefix $(UTILS_DIR),$(UTILS_FILES))

SRCS_MAIN = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAIN_FILES)))
OBJS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAIN_FILES)))
DEPS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_MAIN_FILES)))
SRCS_UTILS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_UTILS_FILES)))
OBJS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_UTILS_FILES)))
DEPS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_UTILS_FILES)))

# ▖▖▖▖▖▖▖▖▖▖▖▖▖▖ BONUS ▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖#

# CLIENT_FILES_BONUS	= client_bonus
# SERVER_FILES_BONUS	= server_bonus

# SRC_FILES_BONUS+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES_BONUS))
# SRC_FILES_BONUS+=$(addprefix $(SERVER_DIR),$(SERVER_FILES_BONUS))

# OBJS_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))
# DEPS_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES_BONUS)))

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ RULES ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
			@$(MKDIR) $(dir $@)
			@echo "$(ORANGE) Compilando objetos  ➟  $(BLUE)$< $(WHITE)"
			@$(CC) -MMD -MP $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: LIBFS $(NAME)

LIBFS:
			@make -C $(LIBFT_DIR)
			@make -C $(LIBMLX_DIR)

$(NAME):	$(OBJS_MAIN) $(OBJS_UTILS)
			@$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBSFT) mlx/libmlx.a $^ -o $@
			@echo "$(ORANGE) Compilando Ejecutables  ➟  $(BLUE)$@ $(WHITE)"

clean :
			@make clean -s -C $(LIBFT_DIR)
			@$(RM) $(OBJ_DIR)
			@echo "$(RED)\n ✗ Archivos objetos Minitalk borrados.‼️\n$(WHITE)";

fclean : clean
			@$(RM) $(NAME)
			@echo "$(BLUE) Todo Super limpito...✌🏼 $(WHITE)" 

re: fclean all
			@echo "$(YELLOW) Borrado todo y recompilado...✌🏼$(WHITE)"

norm:
			@norminette $(SRCS_MAIN) $(SRCS_UTILS) $(INCLUDES) | grep -v Norme -B1 || true

-include $(DEPS)

# ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ Non-file targets ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄#

.PHONY: all clean fclean re norm bonus

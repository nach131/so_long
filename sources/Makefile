# ═══ NAMES ═══════════════════════════════════════════════════════════════════#

NAME		= so_long
# NAME_BONUS	= minitalk_bonus

# ═══ COLORS ══════════════════════════════════════════════════════════════════#

GREEN		=\033[0;32m
BLUE 		=\033[0;34m
ORANGE	=\033[38;5;214m
RED			=\033[0;31m
YELLOW	=\033[0;33m
WHITE		=\033[0;37m

# ═══ COMPILATE ═══════════════════════════════════════════════════════════════#

CC			= gcc
AR 			= ar -rcs
RM			= rm -rf
MKDIR		= -mkdir -p
CFLAGS	= -Wall -Wextra -Werror -g3

# ═══ DIRECTORIES ═════════════════════════════════════════════════════════════#

LIBFT_DIR = libft/
INCLUDES 	= inc/
SRC_DIR 	= src/
OBJ_DIR 	= obj/
# EXE_DIR		= exe/

UTILS_DIR	= utils/
# SERVER_DIR	= server/

# ═══ SOURCES ═════════════════════════════════════════════════════════════════#

LIBSFT = $(LIBFT_DIR)libft.a

MAIN_FILES	=	main
UTILS_FILES	= arr_to_lst maps
# SERVER_FILES	= server
# CLIENT_FILES_BONUS	= client_bonus
# SERVER_FILES_BONUS	= server_bonus

SRC_MAIN_FILES	+=$(MAIN_FILES)
SRC_UTILS_FILES	+=$(addprefix $(UTILS_DIR),$(UTILS_FILES))
# SRC_FILES+=$(addprefix $(SERVER_DIR),$(SERVER_FILES))

# SRC_FILES_BONUS+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES_BONUS))
# SRC_FILES_BONUS+=$(addprefix $(SERVER_DIR),$(SERVER_FILES_BONUS))


# EXE_FILES+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES))
# EXE_FILES+=$(addprefix $(SERVER_DIR),$(SERVER_FILES))

# EXE_FILES_BONUS+=$(addprefix $(CLIENT_DIR),$(CLIENT_FILES_BONUS))
# EXE_FILES_BONUS+=$(addprefix $(SERVER_DIR),$(SERVER_FILES_BONUS))

SRCS_MAIN = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAIN_FILES)))
OBJS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAIN_FILES)))
DEPS_MAIN = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_MAIN_FILES)))
SRCS_UTILS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_UTILS_FILES)))
OBJS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_UTILS_FILES)))
DEPS_UTILS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_UTILS_FILES)))
# EXECS = $(addprefix $(EXE_DIR), $(EXE_FILES))

# SRCS_CLIENT_BONUS += $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_BONUS)))
# OBJS_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))
# DEPS_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES_BONUS)))
# EXECS_BONUS = $(addprefix $(EXE_DIR), $(EXE_FILES_BONUS))


# ═══ RULES ══════════════════════════════════════════════════════════════════#

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
			@$(MKDIR) $(dir $@)
			@echo "$(ORANGE) Compilando objetos  ➟  $(BLUE)$< $(WHITE)"
			@$(CC) -MMD -MP $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: LIBFS $(NAME)

LIBFS:
			@make -C $(LIBFT_DIR)

#$(NAME) : $(OBJS) $(EXEC)

$(NAME):	$(OBJS_MAIN) $(OBJS_UTILS)
			@$(CC) $(CFLAGS) $(LIBSFT) $^ -o $@
			@echo "$(ORANGE) Compilando Ejecutables  ➟  $(BLUE)$@ $(WHITE)"

#$(EXE_DIR)% : $(OBJ_DIR)%.o
#			@$(MKDIR) $(dir $@)
#			@$(CC) $(CFLAGS) -MMD -MP $(LIBSFT) $< -o $@
#			@echo "$(ORANGE) Compilando Ejecutables  ➟  $(BLUE)$< $(WHITE)"

#bonus: LIBFS $(NAME_BONUS)

#$(NAME_BONUS) : $(OBJS_BONUS) $(EXECS_BONUS)

#$(EXE_DIR)% :
#			@$(MKDIR) $(dir $@)
#			$(CC) $(CFLAGS) -MMD -MP $(LIBSFT) -I$(INCLUDES) $< -o $@

clean :
			@make clean -s -C $(LIBFT_DIR)
			@$(RM) $(OBJ_DIR)
			@echo "$(RED)\n ✗ Archivos objetos Minitalk borrados.‼️\n$(WHITE)";
# @$(RM) -rf $(EXE_DIR)

fclean : clean
			@$(RM) $(NAME)
			@echo "$(BLUE) Todo Super limpito...✌🏼$(WHITE)"

re: fclean all
			@echo "$(YELLOW) Borrado todo y recompilado...✌🏼$(WHITE)"

norm:
			@norminette $(SRCS) $(SRCS_CLIENT_BONUS) $(INCLUDES) | grep -v Norme -B1 || true

-include $(DEPS)

# Non-file targets
.PHONY: all clean fclean re norm bonus
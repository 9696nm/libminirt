# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:14:11 by hana/hmori        #+#    #+#              #
#    Updated: 2025/07/08 18:55:11 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET			=	miniRT
PROJECT_NAME	=	miniRT

MAKEFLAGS		+=	--no-print-directory

# -compile rule-
CC				=	gcc
WARNING_FLAG	=	-Wall -Wextra -Werror -Wshadow
OPT_FLAGS		=	-O0
INC_PATHS		=	-I$(DEP_INCLUDES) -Iinternal
LINK_LIBS		=
DEPEND_FLAGS	=	-MMD -MP

# -target-
SRCS_DIR		=	srcs/
OBJS_DIR 		=	objs/

SRC_FILES		=	mrt_destroy.c \
					mrt_init.c \
					mrt_set_value.c
OBJS 			=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SRC_FILES))
DEPS			=	$(patsubst %.c, $(OBJS_DIR)%.d, $(SRC_FILES))

# -color code-
RED				=	"\033[1;31m"
GREEN			= 	"\033[1;32m"
YELLOW			=	"\033[1;33m"
CYAN			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
RESET			=	"\033[0m"


# --rule--
-include $(DEPS)

all: $(LIBFT_DIR) $(MLX_DIR) $(TARGET)

$(TARGET): $(OBJS) $(LIBFTA) $(LIBMLXA)
	$(CC) $(WARNING_FLAG) $(OPT_FLAGS) $(INC_PATHS) $^ -o $@ $(LINK_LIBS)
	@echo $(GREEN)"--- $(PROJECT_NAME) $(COMPILE_TYPE) Compiling Sccusse! ---"$(RESET)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(WARNING_FLAG) $(OPT_FLAGS) $(INC_PATHS) $(DEPEND_FLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

bonus:
	@$(MAKE) all COMPILE_TYPE=bonus

clean:
	@if [ -d $(OBJS_DIR) ]; then \
		rm -rf $(OBJS_DIR); \
		echo $(RED)"$(PROJECT_NAME) $(OBJS_DIR) deleted!"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) object is already deleted."$(RESET); \
	fi

fclean: clean
	@if [ -f $(TARGET) ]; then \
		rm -f $(TARGET); \
		echo $(RED)"$(PROJECT_NAME) $(TARGET) deleted!"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) archive is already deleted."$(RESET); \
	fi

re:	fclean all

.DEFAULT_GOAL := all

.PHONY:	all bonus clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:14:11 by hana/hmori        #+#    #+#              #
#    Updated: 2025/07/26 13:40:55 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MiniRT Library
TARGET			=	libmrt.a
PROJECT_NAME	=	Libminirt

MAKEFLAGS		+=	--no-print-directory

.DEFAULT_GOAL	:=	all


# -compile rule-
CC				=	gcc
WARNING_FLAGS	=	-Wall -Wextra -Werror -Wuninitialized
OPT_FLAGS		=	-O0
INC_PATHS		=	$(addprefix -I,$(INC_DIR))
DEPEND_FLAGS	=	-MMD -MP

AR				=	ar
ARFLAGS			=	rcs

# -target dir-
INC_DIR			=	internal/ $(DEP_INCLUDES)
SRC_DIR			=	srcs/
OBJ_DIR 		=	objs/

# -sources-
SRCS			=	mrt_destroy.c \
					mrt_init.c \
					mrt_set_value.c

TARGET_SRCS		=	$(SRCS)

# -objects-
OBJS 			=	$(patsubst %.c, $(OBJ_DIR)%.o, $(TARGET_SRCS))
DEPS			=	$(patsubst %.c, $(OBJ_DIR)%.d, $(TARGET_SRCS))

# -include-
-include $(DEPS)

# -color code-
RED				=	"\033[1;31m"
GREEN			= 	"\033[1;32m"
YELLOW			=	"\033[1;33m"
CYAN			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
RESET			=	"\033[0m"


# --rule--
all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	@echo $(GREEN)"--- $(PROJECT_NAME) compiled successfully $(COMPILE_TYPE) ---"$(RESET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(WARNING_FLAGS) $(OPT_FLAGS) $(INC_PATHS) $(DEPEND_FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

bonus:
	@$(MAKE) all COMPILE_TYPE=bonus

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo $(RED)"$(PROJECT_NAME) $(OBJ_DIR) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) object has already been deleted."$(RESET); \
	fi

ifeq ($(SKIP_CLEAN), 1)
fclean:
else
fclean: clean
endif
	@if [ -f $(TARGET) ]; then \
		rm -f $(TARGET); \
		echo $(RED)"$(PROJECT_NAME) $(TARGET) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) archive has already been deleted."$(RESET); \
	fi

re:	fclean all

.PHONY:	all bonus clean fclean re

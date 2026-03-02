# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbordeau <cbordeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 13:28:35 by cbordeau          #+#    #+#              #
#    Updated: 2026/02/28 18:07:56 by cbordeau         ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #


NAME       = PMerge
CPP        = c++
CPPFLAGS   = -Wall -Wextra -Werror -std=c++98 -g3
INCLUDES   = -Iincludes -Iclasses/.../

# Dossiers
SRC_PATH   = srcs
CLASS_PATH = classes
OBJ_PATH   = objs

# Sources
SOURCES = \
	$(SRC_PATH)/main.cpp \
	$(SRC_PATH)/utils.cpp \
	$(SRC_PATH)/Vector/PMerge.cpp \
	$(SRC_PATH)/Vector/insertPend.cpp \
	$(SRC_PATH)/Vector/insertPendUtils.cpp \
	$(SRC_PATH)/Vector/swapMain.cpp \
	$(SRC_PATH)/Vector/utils.cpp \
	$(SRC_PATH)/List/PMerge.cpp \
	$(SRC_PATH)/List/insertPend.cpp \
	$(SRC_PATH)/List/insertPendUtils.cpp \
	$(SRC_PATH)/List/swapMain.cpp \
	$(SRC_PATH)/List/utils.cpp \

# Objets (même structure que SOURCES mais dans objs/)
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.cpp=.o))
DEPS = $(OBJS:.o=.d)

# Règle principale
all: $(NAME)

# Édition de lien
$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

# Compilation des .o (recréation des dossiers automatiquement)
$(OBJ_PATH)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# Inclusion des dépendances
-include $(DEPS)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	rm -rf .cache
	rm -rf compile_commands.json
	rm -rf pmerge.txt
	rm -rf Calculator

re: fclean all

bear:
	bear -- make re

.PHONY: all clean fclean re

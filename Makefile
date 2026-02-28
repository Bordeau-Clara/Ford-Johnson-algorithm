# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 08:28:48 by aykrifa           #+#    #+#              #
#                                                                              #
# **************************************************************************** #

PROJECT_DIR = v1
BIN = PMerge

build:
	$(MAKE) -j -C $(PROJECT_DIR)
.PHONY: build

run:
	$(PROJECT_DIR)/$(BIN)
.PHONY: run

run_multiple:
	$(PROJECT_DIR)/$(BIN)
.PHONY: run_multiple

debug:
	valgrind $(PROJECT_DIR)/$(BIN)
.PHONY: debug

debugFork:
	valgrind --trace-children=yes --track-fds=yes $(PROJECT_DIR)/$(BIN)
.PHONY: debug

debugLeaks:
	valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all $(PROJECT_DIR)/$(BIN)
.PHONY: debug

compileCalculator:
	c++ srcs/comparisonCalculator.cpp -o Calculator

test:
	@bash tester.sh $(filter-out $@,$(MAKECMDGOALS))

%:
	@:

fclean:
	$(MAKE) -C $(PROJECT_DIR) fclean
.PHONY: fclean

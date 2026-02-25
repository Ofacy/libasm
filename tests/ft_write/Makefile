# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 00:31:16 by ibertran          #+#    #+#              #
#    Updated: 2026/02/25 16:06:54 by lcottet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = tests

# *** FILES ****************************************************************** #

LIBUNIT_PATH = ../../libunit
LIBASM_PATH = ../../

SRCS = \
	$(addprefix $(FT_STRLEN_DIR), $(FT_STRLEN_SRC))

FT_STRLEN_DIR = results/
FT_STRLEN_SRC = \
				00_main.c \
				basic.c \
				invalid_fd.c \
				invalid_fd_errno.c \

BUILD_DIR := .build/

OBJS = $(SRCS:%.c=$(BUILD_DIR)%.o)

DEPS = $(OBJS:%.o=%.d)

# *** LIBRARIES ************************************************************** #

LIB_NAME	=	ft \
				asm \
				unit_bonus

LIB_PATH 	=	\
				$(LIBASM_PATH)/libasm.a \
				$(LIBUNIT_PATH)/libft/libft.a \
				$(LIBUNIT_PATH)/framework/libunit_bonus.a

HEADERS	= tests.h

INCLUDES	=	$(HEADERS_DIR) \
				$(LIBUNIT_PATH)/framework/includes \
				$(LIB_PATH) \
				$(dir $(HEADERS)) \

# *** CONFIG ***************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -g3 -flto
CPPFLAGS 	= 	$(addprefix -I, $(INCLUDES))
LDFLAGS		=	$(addprefix -L, $(dir $(LIB_PATH)))
LDLIBS		=	$(addprefix -l, $(LIB_NAME))

CC_FLAGS = $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

MKDIR 		= 	mkdir -p $(@D)

MAKEFLAGS	= --no-print-directory

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)

.PHONY : test
test : $(NAME)
	-@./$(NAME)

$(NAME) : $(LIB_PATH) $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN) $(NAME) has been built! $(RESET)"

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBUNIT_PATH)/framework/libunit_bonus.a : FORCE
	@$(MAKE) -C $(@D) bonus

$(LIBASM_PATH)/libasm.a: FORCE
	@$(MAKE) -C $(@D)

-include $(DEPS)

.PHONY : clean
clean :
	$(MAKE) $@ -C $(dir $(LIBUNIT_PATH)/framework/libunit_bonus.a)
	$(MAKE) $@ -C $(dir $(LIBASM_PATH)/libasm.a)
	rm -rf $(BUILD_DIR)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	$(MAKE) $@ -C $(dir $(LIBUNIT_PATH)/framework/libunit_bonus.a)
	$(MAKE) $@ -C $(dir $(LIBASM_PATH)/libasm.a)
	rm -rf $(BUILD_DIR)
	$(RM) $(NAME) $(NAME_BONUS) $(TRACE)
	echo "$(YELLOW) $(NAME) files removed! $(RESET)"

.PHONY : re
re : fclean
	$(MAKE)

.PHONY : print%
print% :
	@echo $(patsubst print%,%,$@)=
	@echo $($(patsubst print%,%,$@))
	
# *** SPECIAL TARGETS ******************************************************** #

.SILENT : clean fclean re debug %debug norminette

.PHONY : FORCE
FORCE :

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m

# **************************************************************************** #
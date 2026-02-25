# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 13:24:31 by lcottet          #+#    #+#              #
#    Updated: 2026/01/05 11:52:10 by lcottet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

AS = nasm
ASFLAG = -g -felf64

AR = ar
ARFLAG = -crs

SRCS_DIR = srcs

SRCS =	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s

OUTDIR = obj

OBJ = $(SRCS:%.s=$(OUTDIR)/%.o)

DEP = $(OBJ:%.o=%.d)

NAME = libasm.a

test_executables = \
	tests/ft_strlen/tests \
	tests/ft_strcpy/tests \
	tests/ft_strcmp/tests \
	tests/ft_write/tests \
	tests/ft_read/tests

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAG) $(NAME) $(OBJ)

$(OUTDIR)/%.o: $(SRCS_DIR)/%.s
	@mkdir -p $(@D)
	$(AS) $(ASFLAG) -o $@ $<

.PHONY: clean
clean:
	rm -rf $(OUTDIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean $(NAME)

%/tests: FORCE
	make -C $(dir $@)

.PHONY: test
test: all $(test_executables)
	@for test in $(test_executables); do \
		$$test;\
	done

.PHONY: FORCE
FORCE:

-include $(DEP)

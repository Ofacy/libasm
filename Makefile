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

SRCS =	ft_strlen.s ft_strcpy.s

OUTDIR = obj

OBJ = $(SRCS:%.s=$(OUTDIR)/%.o)

DEP = $(OBJ:%.o=%.d)

NAME = libasm.a

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

-include $(DEP)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 21:25:29 by jlecomte          #+#    #+#              #
#    Updated: 2021/03/03 11:39:29 by jlecomte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC_F = 	libft_utils.c \
			libft_num.c \
			utils_parse.c \
			utils_conv.c \
			utils_num.c \
			conv_str.c \
			conv_num.c \
			parse.c \
			ft_printf.c \

SRC_DIR = srcs
OBJ_DIR = obj

SRCS 	= $(addprefix $(SRC_DIR)/,$(SRC_F))
OBJS 	= $(addprefix $(OBJ_DIR)/,$(SRC_F:%.c=%.o))

CCF = gcc -Wall -Wextra -Werror

HEADER = includes


all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@echo FT_PRINTF COMPLETE

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@echo Created obj/
	@$(CCF) -I $(HEADER) -o $@ -c $<
	@echo Created: $(@:%=%) 


bonus: all

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

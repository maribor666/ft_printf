# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ospeka <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 16:23:53 by ospeka            #+#    #+#              #
#    Updated: 2018/04/19 16:23:54 by ospeka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
INC =  -I./includes

SRC_NAME = ft_atoi.c \
		ft_count_num.c \
		ft_itoa.c \
		ft_putstr.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_itoabase.c \
		ft_atoi_base.c \
		ft_strsplit.c \
		ft_putchar.c \
		ft_printf.c \
		print_d.c \
		print_o.c \
		print_x.c \
		print_u.c \
		print_p.c \
		print_c.c \
		print_s.c \
		print_percent.c \
		
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(NAME)

$(NAME): $(OBJ)
 @ar rc $(NAME) $(OBJ)
 @ranlib $(NAME)
 @echo "##### Printf Lib created #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
 @mkdir -p $(OBJ_DIR)
 @echo "##### Linking" [ $@ ] " #####"
 @gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
 @rm -f $(OBJ)
 @echo "##### Removed object files #####"

fclean: clean
 @rm -f $(NAME)
 @echo "##### Removed libftprintf.a #####"

re: fclean all

.PHONY: all clean fclean re
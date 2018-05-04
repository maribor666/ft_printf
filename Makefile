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

SRCS =	ft_atoi.c \
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



OBJECTS = $(SRCS:.c=.o)


FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

all: $(NAME)


$(NAME): $(OBJECTS)
	
	@ar rc $(NAME) $(OBJECTS) 
	@echo "///linking of *.o files done|||"

%.o: %.c
	@gcc $(FLAGS) -c $<
	@echo "///*.o files done|||"

clean:
	@rm -f $(OBJECTS)
	@echo "///*.o files deleted|||"

fclean: clean
	@rm  -f $(NAME)
	@echo "///libftprintf.a deleted"

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/03/02 20:34:22 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf
INCLUDES =libft/libft.a
FRAMEW =	-framework OpenGL -framework AppKit
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
SOURCES =	main.c file_reader.c
OBJS =		$(SOURCES:.c=.o)

all :		$(NAME)
$(NAME) :	lib
			$(CC) $(CFLAGS) -c $(SOURCES)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) -lmlx $(FRAMEW)
lib :
			make -C libft/ re
norm :
			norminette $(SOURCES) libft.h
meteo :
			curl http://wttr.in/Paris
clean :
			-rm -f $(OBJS) libft/*.o libft/*.a
fclean :	clean
			-rm -f $(NAME)
re :		fclean all

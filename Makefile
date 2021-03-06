# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/06/10 22:03:45 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf
INCLUDES =	libft/libft.a
HEADER =	fdf.h
MKINC =		make -C libft/
MLX =		-lmlx -framework OpenGL -framework AppKit
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
SOURCES =	main.c file_reader.c image_draw.c converter.c event.c rotate.c
OBJS =		$(SOURCES:.c=.o)

all :		$(NAME)
fonly :
			$(CC) $(CFLAGS) -c $(SOURCES)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)
$(NAME) :	$(OBJS) $(HEADER) Makefile
			$(MKINC)
			$(CC) $(CFLAGS) -c $(SOURCES)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)
norm :
			norminette $(SOURCES) fdf.h
meteo :
			curl http://wttr.in/Paris
clean :
			-rm -f $(OBJS)
fclean :	clean
			$(MKINC) fclean
			-rm -f $(NAME)
re :		fclean all

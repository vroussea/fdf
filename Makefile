# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/03/21 17:30:24 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf
INCLUDES =	libft/libft.a
MKINC =		make -C libft/
MLX =		-lmlx -framework OpenGL -framework AppKit
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
SOURCES =	main.c file_reader.c image_draw.c
OBJS =		$(SOURCES:.c=.o)

all :		$(NAME)
fonly :
			$(CC) $(CFLAGS) -c $(SOURCES)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)
$(NAME) :
			$(MKINC)
			$(CC) $(CFLAGS) -c $(SOURCES)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)
norm :
			norminette $(SOURCES)
meteo :
			curl http://wttr.in/Paris
clean :
			-rm -f $(OBJS)
fclean :	clean
			$(MKINC) fclean
			-rm -f $(NAME)
re :		fclean all

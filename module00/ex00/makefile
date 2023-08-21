# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 12:14:55 by afadlane          #+#    #+#              #
#    Updated: 2023/08/11 12:35:35 by afadlane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = megaphone
CFLAGS = -Wall -Wextra -Werror -std=c++98
CFILES = megaphone.cpp

OBJ = ${CFILES:.cpp=.o}


all : ${NAME}


${NAME} : ${OBJ}
	@c++   $(CFLAGS)  $(CFILES) -o $(NAME) 

clean :
	rm -rf ${OBJ}
fclean : clean 
	rm -rf ${NAME} 
re : fclean all
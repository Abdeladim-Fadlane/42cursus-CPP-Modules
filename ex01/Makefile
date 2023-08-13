# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 12:14:55 by afadlane          #+#    #+#              #
#    Updated: 2023/08/13 11:32:02 by afadlane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = phonebook
CFLAGS = -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp

OBJ = ${CFILES:.cpp=.o}


all : ${NAME}


${NAME} : ${OBJ}
	@g++   $(CFLAGS)  $(CFILES) -o $(NAME) 

clean :
	rm -rf ${OBJ}
fclean : clean 
	rm -rf ${NAME} 
re : fclean all
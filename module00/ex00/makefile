
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
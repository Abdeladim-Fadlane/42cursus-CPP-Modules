
NAME = megaphone
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
CFILES = megaphone.cpp
CXX = c++
OBJ = ${CFILES:.cpp=.o}


all : ${NAME}


${NAME} : ${OBJ}
	@${CXX} $(CXXFLAGS)  $(CFILES) -o $(NAME) 

clean :
	rm -rf ${OBJ}
fclean : clean 
	rm -rf ${NAME} 
re : fclean all
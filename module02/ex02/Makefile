NAME = Fixed
CXX = g++
# CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp Fixed.cpp
OBJ = ${CFILES:.cpp=.o}


all : ${NAME}


${NAME} : ${OBJ}
	@${CXX} $(CXXFLAGS) $(OBJ) -o $(NAME) 

clean :
	@rm -rf ${OBJ}
fclean : clean 
	@rm -rf ${NAME} 
re : fclean all
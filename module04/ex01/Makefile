NAME = Polymorphism
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
CFILES = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJ = ${CFILES:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJ}
	@${CXX}   $(OBJ) -o $(NAME) 

clean :
	@rm -rf ${OBJ}
fclean : clean 
	@rm -rf ${NAME} 
re : fclean all
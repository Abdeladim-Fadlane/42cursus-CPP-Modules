NAME = template

CXXFLAGS = -Wall -Wextra -Werror  #-std=c++98 -fsanitize=address -g3
CFILES =  main.cpp 
CXX = c++
OBJ = ${CFILES:.cpp=.o}

all :${NAME}

${NAME} : ${OBJ}
	${CXX} ${CXXFLAGS} -o $@ $^
	
%.o:%.cpp Array.hpp
	${CXX} ${CXXFLAGS} -c $<

clean :
	@rm -rf ${OBJ}
fclean : clean
	@rm -rf ${NAME}

re : fclean all

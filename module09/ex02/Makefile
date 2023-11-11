NAME = PmergeMe

CXXFLAGS = -Wall -Wextra -Werror  -std=c++98 #-fsanitize=address
CFILES = main.cpp PmergeMe.cpp
CXX = c++
OBJ = ${CFILES:.cpp=.o}

all :${NAME}

${NAME} : ${OBJ}
	${CXX} ${CXXFLAGS} -o $@ $^
	
%.o:%.cpp PmergeMe.hpp
	${CXX} ${CXXFLAGS} -c $<

clean :
	@rm -rf ${OBJ}
fclean : clean
	@rm -rf ${NAME}

re : fclean all

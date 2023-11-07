NAME = btc

CXXFLAGS = -Wall -Wextra -Werror  -std=c++98 -fsanitize=address
CFILES = main.cpp #BitcoinExchange.cpp
CXX = c++
OBJ = ${CFILES:.cpp=.o}

all :${NAME}

${NAME} : ${OBJ}
	${CXX} ${CXXFLAGS} -o $@ $^
	
%.o:%.cpp BitcoinExchange.hpp
	${CXX} ${CXXFLAGS} -c $<

clean :
	@rm -rf ${OBJ}
fclean : clean
	@rm -rf ${NAME}

re : fclean all

NAME = DiamondTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow 
CFILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ = ${CFILES:.cpp=.o}


all : ${NAME}


${NAME}: ${OBJ} #compile object and linking get file exutable
	@${CXX} ${CXXFLAGS} -o $@ $^  

%.o: %.cpp ClapTrap.hpp  #compile source file into object whitout linking
	@${CXX} ${CXXFLAGS} -c $< -o $@

clean :
	@rm -rf ${OBJ}
fclean : clean 
	@rm -rf ${NAME} 
re : fclean all
NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ = ${CFILES:.cpp=.o}


all : ${NAME}


${NAME} : ${OBJ}
	@${CXX} $(CXXFLAGS)  $(OBJ) -o $(NAME) 

clean :
	@rm -rf ${OBJ}
fclean : clean 
	@rm -rf ${NAME} 
re : fclean all
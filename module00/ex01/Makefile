
NAME = phonebook
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
CFILES = main.cpp phonebook.cpp  phonebook_utils.cpp contact.cpp
CXX = c++
OBJ = ${CFILES:.cpp=.o}


all : ${NAME}


${NAME} : ${OBJ}
	@${CXX} $(CXXFLAGS)  $(CFILES) -o $(NAME) 

clean :
	@rm -rf ${OBJ}
fclean : clean 
	@rm -rf ${NAME} 
re : fclean all
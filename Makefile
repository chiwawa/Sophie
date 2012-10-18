CXX     =       g++

NAME    =       Sophie

SRC_DIR =       ./src/

SRC     =       main.cpp

OBJ     =       $(SRC:.cpp=.o)

IFLAGS  =       -I./inc/ -I/usr/local/Cellar/boost/1.51.0/include

LFLAGS  =       -L/usr/local/Cellar/boost/1.51.0/lib -lutil -lboost_system-mt -lboost_filesystem-mt

CXXFLAGS  +=      -W -Wall -pedantic -O3 -ggdb -g3 $(IFLAGS)

RM      =       rm -f

MV      =       mv -f

$(NAME) :       $(OBJ)
		$(CXX) -o $(NAME)  $(LFLAGS) $(OBJ)

all     :       $(NAME)

clean   :
		$(RM) $(OBJ)
		$(RM) ./src/*~
		$(RM) ./src/\#*\#

fclean  :       clean
		$(RM) $(NAME)

re      :       fclean all

.PHONY  :       all clean fclean re

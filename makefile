
CC		= g++
FLGS	= -c -Wall

DIR 	= $(shell pwd)
INCLUDE	= $(DIR)/lib
SRC_DIR	= $(DIR)/src
OBJ_DIR	= $(DIR)/obj

SRC		= $(wildcard $(SRC_DIR)/*.cpp)
LIB 	= $(wildcard $(INCLUDE)/*.hpp)
OBJ 	= $(patsubst %.cpp, %.o, $(subst src,obj,$(SRC)))

info	= "\
Makefile Manual.\n\
make [Options]:\n\
1. main -\n\
3. unk -\n\
2. clean -\n\
\n\
Other options:\n\
1. panorama.sh -\n\
2. modify.sh -"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp # $(INCLUDE)/%.hpp
	$(CC) $(FLGS) -I $(INCLUDE) $? -o $@ # $<

main: $(OBJ)
	$(CC) -g $(OBJ) -o $@

direct:
	$(CC) $(subst $(OBJ_DIR)/run.o, ,$(OBJ)) -o main

clean:
	$(RM) $(OBJ)

info:
	@echo $(info)

library:
	@echo $(LIB)

source:
	@echo $(SRC)

object:
	@echo $(OBJ)

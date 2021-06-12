CC := g++
PROGRAM := pwd
INCLUDE := -I .
SRC := main.cpp

all: $(PROGRAM)

$(PROGRAM):
	@$(CC) -o $(PROGRAM) $(SRC) $(INCLUDE)

fclean:
	@rm -f $(PROGRAM)

re: fclean all

.PHONY: all fclean re 

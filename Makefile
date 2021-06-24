CC := g++
PROGRAM := pw
INCLUDE := -I ./includes

CLASS_DIR := ./src/classes
CLASS_FILE += Generate.cpp
CLASS_FILE += Invault.cpp
CLASS_FILE += Outvault.cpp
CLASS_FILE += Parser.cpp
CLASS_FILE += Vault.cpp
CLASSES := $(addprefix $(CLASS_DIR)/,$(CLASS_FILE))

SRC := src/main.cpp
SRC += $(CLASSES)

all: $(PROGRAM)

$(PROGRAM):
	@$(CC) -o $(PROGRAM) $(SRC) $(INCLUDE)

clean:
	@rm -f $(PROGRAM)

re: clean all

.PHONY: all fclean re 

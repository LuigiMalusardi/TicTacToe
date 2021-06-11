COMPILER_MODE	:=	C

#Compiler C
CC	:=	gcc
CFLAGS	:= -Wall -ggdb

#Compiler C++
CXX	:=	g++
CXX_FLAGS := -std=c++17 -ggdb

#BIN files
BIN := bin

#CPP or C files
SRC:= src

#H files
INCLUDE:= include

# Executable name
EXECUTABLE := main

COMPILER =
FLAGS =
EXTENSION = 

ifeq ($(COMPILER_MODE), C)
	COMPILER = CC
	FLAGS = CFLAGS
	EXTENSION = c
else
	COMPILER = CXX
	FLAGS = CXX_FLAGS
	EXTENSION = cpp
endif

#MAKE ALL
all: $(BIN)*.o
	$(info Compiled with success!)

#Compila e avvia il programma
run: clean all
	cls
	./$(BIN)/$(EXECUTABLE).exe

#COMPILE .o FILES
$(BIN)*.o:	$(SRC)/*.$(EXTENSION)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $(SRC)/*.$(EXTENSION) -o $(BIN)/$(EXECUTABLE) $(LIBRARIES)


#Elimina il contenuto della cartella BIN (comando windows del    forzata e senza richiesta conferma)
clean:
	del /F /Q .\$(BIN)\*
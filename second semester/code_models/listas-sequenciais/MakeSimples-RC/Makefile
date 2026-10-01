APPS = .
BIN = .
INCLUDE = .
OBJ = .
SRC = .


all:
	gcc -c $(SRC)/ListaSequencial.c  -I $(INCLUDE)/ -o $(OBJ)/ListaSequencial.o
	gcc $(APPS)/main.c $(OBJ)/ListaSequencial.o -I $(INCLUDE) -o $(BIN)/ListaSequencial.exe -lm

run:
	$(BIN)/ListaSequencial.exe

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*.exe
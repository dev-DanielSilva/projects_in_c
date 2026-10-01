# ==========================================
# MAKEFILE - LISTA DINÂMICA ENCADEADA (LDES)
# ==========================================

# 1. Definição de variáveis
CC = gcc
CFLAGS = -Wall -std=c99 -g
TARGET = main

# 2. Arquivos objeto (.o) necessários para o projeto
OBJS = main.o ListaDinEncad.o

# 3. Nome do pacote para o RunCodes
ZIP_NAME = submissao.zip

# ------------------------------------------
# Regras principais
# ------------------------------------------

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ------------------------------------------
# Atalhos úteis
# ------------------------------------------

run: all
	./$(TARGET)

zip:
	zip $(ZIP_NAME) main.c ListaDinEncad.c ListaDinEncad.h Makefile

clean:
	rm -f *.o $(TARGET) $(ZIP_NAME)

rebuild: clean all

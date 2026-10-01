# ==========================================
# ESTRUTURA GENÉRICA DE UM MAKEFILE
# ==========================================

# 1. Definição de variáveis para facilitar alterações futuras
CC = gcc                     # O compilador que será usado (geralmente gcc)
CFLAGS = -Wall -g             # Flags de compilação (-Wall avisa sobre erros, -g ajuda a debugar)
TARGET = calculadora         # Nome do executável final que será gerado

# 2. Arquivos objeto (.o) necessários para o projeto
OBJS = main.o PilhaDin.o

# ------------------------------------------
# Regras principais
# ------------------------------------------

# 'all' é o alvo padrão. Quando você digita apenas 'make', ele roda isso.
all: $(TARGET)

# Como o executável final é montado juntando todos os objetos
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lm

# Regra genérica para compilar qualquer arquivo .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ------------------------------------------
# Atalhos úteis
# ------------------------------------------

# Regra para compilar e rodar automaticamente (digite: make run)
run: all
	./$(TARGET)

# Regra para apagar arquivos temporários de compilação e zips antigos
clean:
	rm -f *.o $(TARGET) *.zip

# Regra para recompilar tudo do zero (limpa e compila de novo)
rebuild: clean all

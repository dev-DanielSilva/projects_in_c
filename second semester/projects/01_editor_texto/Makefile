CFLAGS = -Wall -g
TARGET = programa

OBJS = main.o LDED.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f *.o $(TARGET) *.zip

rebuild: clean all

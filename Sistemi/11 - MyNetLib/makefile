# Compilatore
CC = gcc
# Flag di compilazione
CFLAGS = -Wall -Wextra -g

# Nome dell'eseguibile finale
TARGET = netlib

# File oggetto (.o) da generare
OBJS = main.o my_net_lib.o

# Regola predefinita (build completo)
all: $(TARGET)

# Link degli oggetti per creare l'eseguibile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilazione dei singoli file .c in .o
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Pulizia dei file generati
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild pulendo prima
rebuild: clean all

.PHONY: all clean rebuild
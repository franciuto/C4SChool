# Tutorial: Compilazione Multifile con GCC e Makefile

## Parte 1: Compilazione Multifile con GCC

### Introduzione
Quando un progetto C cresce, è buona pratica dividere il codice in più file. GCC permette di compilare progetti multifile in diversi modi.

### Struttura Base di un Progetto Multifile

Un progetto tipico è composto da:
- **File header (.h)**: contengono dichiarazioni di funzioni e definizioni
- **File sorgente (.c)**: contengono implementazioni delle funzioni
- **File main (.c)**: contiene la funzione main e il punto di ingresso del programma

**Esempio di struttura:**
```
progetto/
├── main.c
├── funzioni.c
└── funzioni.h
```

### Metodo 1: Compilazione Diretta (One-Shot)

Il modo più semplice è compilare tutti i file sorgente in un unico comando:

```bash
gcc main.c funzioni.c -o programma
```

**Vantaggi:** Semplice e veloce per progetti piccoli  
**Svantaggi:** Ricompila tutto ogni volta, anche file non modificati

### Metodo 2: Compilazione Separata (Recommended)

Questo metodo compila ogni file separatamente in object file (.o), poi li collega insieme.

#### Step 1: Compilare i file sorgente in object file
```bash
gcc -c main.c -o main.o
gcc -c funzioni.c -o funzioni.o
```

L'opzione `-c` dice a GCC di compilare senza fare il linking.

#### Step 2: Linking degli object file
```bash
gcc main.o funzioni.o -o programma
```

**Vantaggi:** 
- Ricompili solo i file modificati
- Più veloce per progetti grandi
- Migliore organizzazione

### Esempio Pratico Completo

**funzioni.h:**
```c
#ifndef FUNZIONI_H
#define FUNZIONI_H

int somma(int a, int b);
int prodotto(int a, int b);

#endif
```

**funzioni.c:**
```c
#include "funzioni.h"

int somma(int a, int b) {
    return a + b;
}

int prodotto(int a, int b) {
    return a * b;
}
```

**main.c:**
```c
#include <stdio.h>
#include "funzioni.h"

int main() {
    printf("Somma: %d\n", somma(5, 3));
    printf("Prodotto: %d\n", prodotto(5, 3));
    return 0;
}
```

**Compilazione:**
```bash
# Metodo 1: One-shot
gcc main.c funzioni.c -o programma

# Metodo 2: Separata
gcc -c main.c -o main.o
gcc -c funzioni.c -o funzioni.o
gcc main.o funzioni.o -o programma

# Esecuzione
./programma
```

### Opzioni Utili di GCC

- `-Wall`: Abilita tutti i warning
- `-Wextra`: Abilita warning extra
- `-g`: Include informazioni di debug
- `-O2`: Ottimizzazione livello 2
- `-o <nome>`: Specifica il nome dell'output
- `-I<directory>`: Specifica dove cercare file header
- `-L<directory>`: Specifica dove cercare librerie

**Esempio con opzioni:**
```bash
gcc -Wall -Wextra -g -c main.c -o main.o
gcc -Wall -Wextra -g -c funzioni.c -o funzioni.o
gcc main.o funzioni.o -o programma
```

---

## Parte 2: Automazione con Makefile

### Introduzione a Make

Make è uno strumento che automatizza il processo di compilazione. Legge le istruzioni da un file chiamato `Makefile` o `makefile`.

### Struttura Base di un Makefile

```makefile
target: dipendenze
	comando
```

**Nota:** Il comando deve essere preceduto da un TAB (non spazi)!

### Makefile Semplice

```makefile
# Compilatore e flag
CC = gcc
CFLAGS = -Wall -Wextra -g

# Nome dell'eseguibile
TARGET = programma

# File oggetto
OBJS = main.o funzioni.o

# Regola principale
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Regole per i file oggetto
main.o: main.c funzioni.h
	$(CC) $(CFLAGS) -c main.c

funzioni.o: funzioni.c funzioni.h
	$(CC) $(CFLAGS) -c funzioni.c

# Pulizia dei file generati
clean:
	rm -f $(OBJS) $(TARGET)
```

### Utilizzo del Makefile

```bash
# Compila il progetto
make

# Pulisce i file generati
make clean

# Ricompila tutto
make clean && make
```

### Makefile Avanzato con Pattern Rules

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = programma
SRCS = main.c funzioni.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
```

**Spiegazione:**
- `%.o: %.c`: Pattern rule - compila qualsiasi .c in .o
- `$<`: Primo prerequisito (file .c)
- `$@`: Target corrente (file .o)
- `.PHONY`: Dichiara target che non sono file reali

---

## Differenze Windows vs Linux

### Linux

Su Linux, make è solitamente già installato o facilmente installabile:

```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# Fedora/RHEL
sudo dnf install gcc make

# Arch
sudo pacman -S base-devel
```

**Uso:**
```bash
make
make clean
./programma
```

### Windows

Su Windows hai diverse opzioni:

#### Opzione 1: MinGW-w64

1. Installa MinGW-w64 da [winlibs.com](https://winlibs.com)
2. Aggiungi alla PATH: `C:\mingw64\bin`
3. Usa `mingw32-make` invece di `make`

```cmd
mingw32-make
mingw32-make clean
programma.exe
```

**Makefile per Windows (modifica clean):**
```makefile
clean:
	del /Q $(OBJS) $(TARGET).exe
```

#### Opzione 2: MSYS2

1. Installa MSYS2 da [msys2.org](https://msys2.org)
2. Apri MSYS2 terminal
3. Installa tools:
```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make
```

4. Usa `make` normalmente nella shell MSYS2

#### Opzione 3: WSL (Windows Subsystem for Linux)

1. Abilita WSL su Windows 10/11
2. Installa una distribuzione Linux (es. Ubuntu)
3. Usa gli stessi comandi Linux

```bash
sudo apt install build-essential
make
./programma
```

### Makefile Cross-Platform

Per rendere il Makefile compatibile con entrambi i sistemi:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = programma
SRCS = main.c funzioni.c
OBJS = $(SRCS:.c=.o)

# Rilevamento OS
ifeq ($(OS),Windows_NT)
    RM = del /Q
    TARGET := $(TARGET).exe
else
    RM = rm -f
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)

.PHONY: all clean
```

---

## Consigli Pratici

1. **Usa sempre header guards** nei file .h per evitare inclusioni multiple
2. **Compila con `-Wall -Wextra`** per trovare potenziali errori
3. **Usa make invece di compilare manualmente** per progetti con più di 2-3 file
4. **Versiona il Makefile** insieme al codice nel repository
5. **Documenta le dipendenze** nel Makefile per chiarezza
6. **Usa .PHONY** per target che non generano file
7. **Testa su entrambe le piattaforme** se il progetto deve essere cross-platform

## Risorse Aggiuntive

- [GCC Manual](https://gcc.gnu.org/onlinedocs/)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [GCC Warning Options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)

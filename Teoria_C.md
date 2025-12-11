# Guida per la Verifica di Programmazione C

## Indice degli Argomenti

1. [Gestione dei File in C](#1-gestione-dei-file-in-c)
   - 1.1 [Apertura e Chiusura File](#11-apertura-e-chiusura-file)
   - 1.2 [Lettura e Scrittura](#12-lettura-e-scrittura)
   - 1.3 [Gestione Errori](#13-gestione-errori)
   - 1.4 [File CSV e Parsing](#14-file-csv-e-parsing)

2. [Struct (Strutture)](#2-struct-strutture)
   - 2.1 [Definizione e Typedef](#21-definizione-e-typedef)
   - 2.2 [Notazione . vs ->](#22-notazione--vs--)
   - 2.3 [Passaggio per Valore vs Puntatore](#23-passaggio-per-valore-vs-puntatore)
   - 2.4 [Padding e Allineamento](#24-padding-e-allineamento)
   - 2.5 [Struct Packed](#25-struct-packed)
   - 2.6 [Bitfield](#26-bitfield)
   - 2.7 [Array di Struct](#27-array-di-struct)

3. [Enum (Enumerazioni)](#3-enum-enumerazioni)
   - 3.1 [Definizione e Utilizzo](#31-definizione-e-utilizzo)
   - 3.2 [Valori Personalizzati](#32-valori-personalizzati)
   - 3.3 [Conversione enum-stringa](#33-conversione-enum-stringa)

4. [Union](#4-union)
   - 4.1 [Concetto di Union](#41-concetto-di-union)
   - 4.2 [Tagged Union](#42-tagged-union)
   - 4.3 [Polimorfismo in C](#43-polimorfismo-in-c)

5. [Parametri da Linea di Comando](#5-parametri-da-linea-di-comando)
   - 5.1 [argc e argv](#51-argc-e-argv)
   - 5.2 [Parsing degli Argomenti](#52-parsing-degli-argomenti)

6. [Funzioni di Manipolazione Stringhe](#6-funzioni-di-manipolazione-stringhe)
7. [Concetti Trasversali](#7-concetti-trasversali)

---

## 1. Gestione dei File in C

### 1.1 Apertura e Chiusura File

**`fopen()`** - Apre un file:
```c
FILE *f = fopen("nomefile.txt", "w");  // "w" = write, "r" = read, "a" = append
if (!f) {
    perror("Errore apertura file");
    return;
}
```

**Modalità di apertura:**
- `"r"` - lettura (il file deve esistere)
- `"w"` - scrittura (crea nuovo file o sovrascrive)
- `"a"` - append (aggiunge alla fine)
- `"r+"` - lettura e scrittura
- `"w+"` - lettura e scrittura (sovrascrive)
- `"a+"` - lettura e append

**`fclose()`** - Chiude il file:
```c
if (fclose(f) != 0)
    perror("Errore chiusura file");
```

**IMPORTANTE:** Chiudere sempre i file dopo l'uso!

### 1.2 Lettura e Scrittura

**`fprintf()`** - Scrittura formattata:
```c
fprintf(f, "Nome: %s, Età: %d\n", nome, eta);
```

**`fgets()`** - Legge una riga intera:
```c
char buf[128];
while (fgets(buf, sizeof(buf), f)) {
    // Processa la riga
}
```
- Ritorna `NULL` quando raggiunge EOF o in caso di errore
- Include il carattere `\n` nella stringa letta

**`fscanf()`** - Lettura formattata:
```c
int eta;
float stipendio;
char nome[32];
if (fscanf(f, "%31s\t%d\t%f\n", nome, &eta, &stipendio) == 3) {
    // Lettura riuscita
}
```
- Ritorna il numero di elementi letti con successo
- Il numero prima di `s` (es. `%31s`) limita la lunghezza per evitare overflow

### 1.3 Gestione Errori

**`ferror()`** - Verifica se si è verificato un errore:
```c
if (ferror(f))
    perror("Errore di lettura");
```

**`perror()`** - Stampa un messaggio di errore descrittivo:
```c
perror("Descrizione errore");  // Stampa: "Descrizione errore: [messaggio di sistema]"
```

### 1.4 File CSV e Parsing

**`strtok()`** - Tokenizza una stringa:
```c
char *token = strtok(line, ";");  // Primo token
while (token != NULL) {
    // Processa token
    token = strtok(NULL, ";");    // Token successivi
}
```
**ATTENZIONE:** `strtok()` modifica la stringa originale!

**`atoi()`** - Converte stringa in intero:
```c
int numero = atoi("123");  // numero = 123
```

**`strtod()`** - Converte stringa in double:
```c
double valore = strtod("3.14", NULL);
```

**`strcspn()`** - Trova il primo carattere che corrisponde:
```c
buf[strcspn(buf, "\r\n")] = '\0';  // Rimuove \n o \r dalla fine
```

---

## 2. Struct (Strutture)

### 2.1 Definizione e Typedef

**Definizione tradizionale:**
```c
struct Point {
    int x;
    int y;
};

struct Point p1;  // Devi usare "struct"
```

**Con typedef (stile moderno/professionale):**
```c
typedef struct {
    int x;
    int y;
} Point;

Point p1;  // Più pulito!
```

**Convenzione:** I tipi definiti dall'utente finiscono con `_t`:
```c
typedef struct {
    char name[16];
    int level;
} hero_t;
```

### 2.2 Notazione . vs ->

**Operatore `.` (punto)** - Accesso diretto con variabile:
```c
Point p1;
p1.x = 10;
p1.y = 20;
```

**Operatore `->` (freccia)** - Accesso tramite puntatore:
```c
Point *ptr = &p1;
ptr->x = 30;  // Equivalente a: (*ptr).x = 30
ptr->y = 40;
```

**REGOLA:**
- Variabile normale → usa `.`
- Puntatore → usa `->`

### 2.3 Passaggio per Valore vs Puntatore

**Per valore** (copia l'intera struct):
```c
hero_t hero_create(const char *name, int level) {
    hero_t h;
    h.level = level;
    return h;  // Ritorna una COPIA
}
```
- Pro: Semplice, non ci sono side-effects
- Contro: Inefficiente per struct grandi

**Per puntatore** (passa solo l'indirizzo):
```c
void hero_print(const hero_t *h) {  // const = non modificabile
    printf("%s\n", h->name);
}

void hero_level_up(hero_t *h) {  // Modifica l'originale
    h->level++;
}
```
- Pro: Efficiente, permette modifiche
- Contro: Attenzione ai side-effects

### 2.4 Padding e Allineamento

**Problema:** Il compilatore aggiunge byte "vuoti" (padding) per allineare i dati in memoria.

**Struct mal progettata:**
```c
struct Bad {
    char a;   // 1 byte
              // [3 byte padding]
    int b;    // 4 bytes
    char c;   // 1 byte
              // [3 byte padding]
    int d;    // 4 bytes
};  // Totale: 16 bytes (6 byte sprecati!)
```

**Struct ben progettata:**
```c
struct Good {
    int b;    // 4 bytes
    int d;    // 4 bytes
    char a;   // 1 byte
    char c;   // 1 byte
              // [2 byte padding finale]
};  // Totale: 12 bytes (2 byte sprecati)
```

**REGOLA D'ORO:** Ordina i membri dal più grande al più piccolo!

**`offsetof()`** - Trova l'offset di un membro:
```c
#include <stddef.h>
size_t offset = offsetof(struct Bad, b);  // Offset del campo 'b'
```

**`sizeof()`** - Dimensione della struct:
```c
printf("Dimensione: %zu bytes\n", sizeof(struct Bad));
```

### 2.5 Struct Packed

Elimina il padding (GCC/Clang):
```c
struct __attribute__((packed)) Packed {
    char a;
    int b;
    char c;
};  // Dimensione = esattamente la somma dei membri
```

**ATTENZIONE:**
- Accesso più LENTO
- Può causare crash su alcune architetture
- Usare solo per protocolli di rete o file binari

### 2.6 Bitfield

Permette di specificare il numero esatto di bit per ogni campo:

```c
typedef struct {
    unsigned powered_on : 1;  // 1 bit
    unsigned tx_busy    : 1;  // 1 bit
    unsigned channel    : 4;  // 4 bit (valori 0-15)
    unsigned rssi_level : 3;  // 3 bit (valori 0-7)
    unsigned modulation : 2;  // 2 bit (valori 0-3)
    unsigned            : 3;  // 3 bit non usati (riservati)
} radio_status_t;
```

**Quando usare:**
- Registri hardware
- Protocolli di comunicazione
- Risparmio memoria (es. flag booleani)

**ATTENZIONE:** Il layout è implementation-defined (non portabile)!

### 2.7 Array di Struct

```c
hero_t party[5];  // Array di 5 eroi

// Inizializzazione
party[0] = hero_create("Frodo", 12);

// Accesso
party[0].level = 15;

// Iterazione
for (int i = 0; i < 5; i++) {
    hero_print(&party[i]);  // Passa l'indirizzo
}

// Puntatore che scorre l'array
hero_t *ptr = party;
for (int i = 0; i < 5; i++) {
    printf("%s\n", ptr->name);
    ptr++;  // Avanza di sizeof(hero_t) byte
}
```

---

## 3. Enum (Enumerazioni)

### 3.1 Definizione e Utilizzo

**Definizione:**
```c
typedef enum {
    LIGHT_RED,      // 0
    LIGHT_YELLOW,   // 1
    LIGHT_GREEN     // 2
} traffic_light_t;
```

**Utilizzo:**
```c
traffic_light_t light = LIGHT_RED;

switch (light) {
    case LIGHT_RED:
        printf("STOP\n");
        break;
    case LIGHT_YELLOW:
        printf("GET READY\n");
        break;
    case LIGHT_GREEN:
        printf("GO\n");
        break;
}
```

**Cosa è un enum:**
- Una serie di costanti intere con un nome
- Rende il codice leggibile (no "numeri magici")
- Sotto sotto è un `int`

### 3.2 Valori Personalizzati

Puoi assegnare valori specifici:
```c
typedef enum {
    LIGHT_RED    = 10,
    LIGHT_YELLOW = 20,
    LIGHT_GREEN  = 30
} traffic_light_t;
```

### 3.3 Conversione enum-stringa

Gli enum non sono stringhe! Serve una funzione:
```c
const char *light_to_string(traffic_light_t light) {
    switch (light) {
        case LIGHT_RED:    return "RED";
        case LIGHT_YELLOW: return "YELLOW";
        case LIGHT_GREEN:  return "GREEN";
        default:           return "UNKNOWN";
    }
}
```

**ATTENZIONE:**
```c
printf("%d\n", LIGHT_RED);   // OK: stampa 0
printf("%s\n", LIGHT_RED);   // ERRORE: enum non è una stringa!
```

---

## 4. Union

### 4.1 Concetto di Union

Una union condivide lo stesso spazio di memoria tra più campi:

```c
union Data {
    int i;       // 4 bytes
    float f;     // 4 bytes
    char s[32];  // 32 bytes
};  // sizeof(union Data) = 32 bytes (il più grande!)
```

**Differenza con struct:**
- **Struct:** Ogni campo ha la sua memoria separata
- **Union:** Tutti i campi condividono la stessa memoria

**ATTENZIONE:** Puoi leggere solo l'ultimo campo scritto!

```c
union Data d;
d.i = 42;
printf("%d\n", d.i);  // OK: 42
printf("%f\n", d.f);  // ERRORE: valore indefinito!
```

### 4.2 Tagged Union

Pattern per usare le union in modo sicuro:

```c
typedef enum { INT, FLOAT, STRING } Type;

typedef struct {
    Type type;          // TAG: indica quale campo è valido
    union {
        int i;
        float f;
        char s[32];
    } data;
} Value;
```

**Utilizzo:**
```c
Value v;
v.type = INT;
v.data.i = 42;

// Lettura sicura
switch (v.type) {
    case INT:
        printf("%d\n", v.data.i);
        break;
    case FLOAT:
        printf("%f\n", v.data.f);
        break;
    case STRING:
        printf("%s\n", v.data.s);
        break;
}
```

### 4.3 Polimorfismo in C

La tagged union permette di implementare polimorfismo in C:

```c
Value make_int(int n) {
    Value v;
    v.type = INT;
    v.data.i = n;
    return v;
}

Value add(Value a, Value b) {
    if (a.type == INT && b.type == INT) {
        return make_int(a.data.i + b.data.i);
    }
    // ... gestisci altri tipi
}
```

**Vantaggi:**
- Stessa funzione, comportamenti diversi
- Type safety (controllo a runtime)
- Risparmio memoria rispetto a struct

---

## 5. Parametri da Linea di Comando

### 5.1 argc e argv

**Firma main con parametri CLI:**
```c
int main(int argc, char *argv[])
```

- **`argc`** (argument count): Numero di argomenti (include il nome del programma)
- **`argv`** (argument vector): Array di stringhe

**Esempio:**
```bash
./programma ciao mondo --verbose
```

```c
argc = 4
argv[0] = "./programma"
argv[1] = "ciao"
argv[2] = "mondo"
argv[3] = "--verbose"
argv[4] = NULL  // L'ultimo elemento è sempre NULL
```

### 5.2 Parsing degli Argomenti

**Controllo numero minimo argomenti:**
```c
if (argc < 2) {
    printf("Uso: %s <nome>\n", argv[0]);
    return 1;
}
```

**Parsing opzioni:**
```c
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--times") == 0 && i + 1 < argc) {
        int times = atoi(argv[++i]);  // Preleva il valore dopo --times
    }
    else if (strcmp(argv[i], "--shout") == 0) {
        // Opzione flag (senza valore)
    }
    else {
        printf("Opzione sconosciuta: %s\n", argv[i]);
    }
}
```

**ATTENZIONE:**
- Verifica sempre che ci siano abbastanza argomenti (`i + 1 < argc`)
- `atoi()` non controlla errori (ritorna 0 se la stringa non è un numero)

---

## 6. Funzioni di Manipolazione Stringhe

### Copia Stringhe

**`strncpy()`** - Copia limitata:
```c
char dest[16];
strncpy(dest, src, sizeof(dest));
dest[sizeof(dest)-1] = '\0';  // Garantisce terminazione!
```

**`snprintf()`** - Copia formattata sicura (alternativa migliore):
```c
snprintf(dest, sizeof(dest), "%s", src);  // Garantisce sempre terminazione
```

### Confronto Stringhe

**`strcmp()`** - Confronta due stringhe:
```c
if (strcmp(str1, str2) == 0) {
    printf("Stringhe uguali\n");
}
```
- Ritorna 0 se uguali
- < 0 se str1 < str2
- > 0 se str1 > str2

### Conversione

**`atoi()`** - Stringa → int:
```c
int n = atoi("123");  // n = 123
```

**`toupper()`** / **`tolower()`** - Maiuscole/minuscole:
```c
#include <ctype.h>
char c = toupper('a');  // c = 'A'
```

**Conversione stringa intera:**
```c
char *str = buf;
while (*str) {
    *str = toupper(*str);
    str++;
}
```

---

## 7. Concetti Trasversali

### Const

**`const` con puntatori:**
```c
const hero_t *h;         // Non puoi modificare la struct puntata
hero_t *const h;         // Non puoi modificare il puntatore
const hero_t *const h;   // Entrambi immutabili
```

**Uso tipico:**
```c
void hero_print(const hero_t *h) {
    // h->level = 10;  // ERRORE: h è const
    printf("%d\n", h->level);  // OK: lettura
}
```

### Casting

**Cast esplicito:**
```c
uint16_t raw = *(uint16_t *)&st;  // Vista grezza a 16 bit della struct
unsigned char *bytes = (unsigned char *)ptr;  // Vista a byte
```

**ATTENZIONE:** I cast aggrano la type safety del compilatore!

### Best Practices

1. **File:** Controlla sempre `NULL` dopo `fopen()`, chiudi sempre con `fclose()`
2. **Stringhe:** Usa sempre `strncpy()` o `snprintf()` per evitare buffer overflow
3. **Struct:** Ordina membri dal più grande al più piccolo per ridurre padding
4. **Enum:** Usa sempre `switch` con `default` per gestire valori inattesi
5. **Union:** Usa sempre tagged union per type safety
6. **CLI:** Verifica sempre `argc` prima di accedere a `argv[i]`

### Controllo Errori

**Pattern comune:**
```c
FILE *f = fopen(filename, "r");
if (!f) {
    perror("Errore apertura");
    return -1;  // Codice errore
}

// ... operazioni sul file ...

if (ferror(f)) {
    perror("Errore lettura");
    fclose(f);
    return -1;
}

fclose(f);
return 0;  // Successo
```

---

## Riepilogo Rapido per la Verifica

### File
- `fopen()`, `fclose()`, `fprintf()`, `fgets()`, `fscanf()`
- `ferror()`, `perror()`
- `strtok()`, `atoi()`, `strtod()`

### Struct
- Definizione con `typedef`
- `.` per variabili, `->` per puntatori
- Padding e allineamento (ordina dal grande al piccolo)
- Bitfield per registri hardware
- `sizeof()`, `offsetof()`

### Enum
- Costanti intere nominate
- Non sono stringhe!
- Conversione manuale con `switch`

### Union
- Condivisione memoria
- Tagged union per type safety
- Polimorfismo in C

### Parametri CLI
- `argc` = numero argomenti
- `argv[0]` = nome programma
- Parsing con `strcmp()` e loop

### Stringhe
- `strncpy()`, `snprintf()` (sicure)
- `strcmp()` (confronto)
- `toupper()`, `tolower()` (conversione)

---
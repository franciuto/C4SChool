## quale errore viene segnalato al sistema quando terminano i fd
fopen segnala un "too many files open"

## il programma rilascia correttamente tutte le risorse
ovvio 😎

## riesci a far provocare altri tipi di errori al SO
rm -rf /sbin/init it's fun

## cosa cambia se riduci le risorse con ulimit -n
con ulimit -n posso impostare un limite per la mia shell corrente, per esempio con ulimit -n 100 vado a dire al SO quanti file descriptor può avere aperti al massimo per questa sessione

```bash
🙈 15 - openloop git:(main) ✗ ulimit -n 100 
🙈 15 - openloop git:(main) ✗ ./openloop aura.txt
fopen: Too many open files
Aperture riuscite: 97
Aperture fallite: 1
File descriptor usati: 3 -> 99
🙈 15 - openloop git:(main) ✗ 
```

posso anche settare valori molto grandi, ma macOS è chiaramente limitato sotto questo punto di vista. Arch is better btw
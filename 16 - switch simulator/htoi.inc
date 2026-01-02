// htoi.inc - Converte una stringa esadecimale in un intero
// Esempio: htoi("A1") restituisce 161, htoi("FF") restituisce 255

int htoi(char s[]) {
    int i, n;
    n = 0;

    for (i = 0; s[i] != '\0'; i++) {
        n *= 16;
        if (s[i] >= '0' && s[i] <= '9')
            n += s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            n += s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            n += s[i] - 'A' + 10;
    }
    return n;
}

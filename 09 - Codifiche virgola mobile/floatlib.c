/* Library to encode and decode float numbers*/
#include "floatlib.h"
#include <stdio.h>

void encodeFloat (float n) {
    int s;  // Integer to store the sign
    int e;  // Integer to store the exponent
    unsigned int m;  // Unsigned int to store the mantissa

    /* ENCODING */
    // Codifica del segno tramite un metodo lineare, senza condizioni (no salti)
    s = -2 * ((unsigned int)n >> 31) + 1;
    // Codifica dell' esponente
    e = (((unsigned int)n >> 23)&0xFF) - 127;
    // Codifica della mantissa
    m = (unsigned int)n & 0x007FFFFF;

    printf("%d %d %u" , s, e , m);      // DEBUG
}
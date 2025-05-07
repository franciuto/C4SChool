#include <stdint.h>
/************************************************************************
* FILENAME : ffo_lib.h
*
* DESCRIPTION :
*      Library of functions
*
* RETURN :
*        Restituisce 0 in caso di successo, altri valori per indicare errori
*
* USAGE:
* >> gcc -o output -------.c
* >> ./output [eventuali parametri]
*
* AUTHOR:  	 		START DATE :
*        Francesco Fontanesi                 7/05/2025
**
* CHANGES :
*        Data      Versione    Descrizione
*        7/05/2025  1.00       Initial creation of the file
*
*
************************************************************************/

/* ---- FUNCTION: contaVocali ----
    Inputs:                          
        This function receives the string from it will count the vowels from as a pointer to char
    
    Return:
        Returns the number of vowels in the string as an integer
    
*/
int contaVocali(const char* s);

/* ---- FUNCTION: GetNetwork ----
    Inputs:                          
        ip = ip as string
        mask = mask as string    
    Return:
        Returns the network part of the ip address calculated using a bitwise AND between the ip and masks
    
*/
char* getNetwork (const char* ip, const char* netmask);

/* ---- FUNCTION: generaTavolozzaRGB ----
    Inputs:   
        n = numbers of terns to make                       
    Return:
        Returns the uint32_t of hex rgb colors 
    
*/
uint32_t* generaTavolozzaRGB(int n);

#include "vectlib.h"

// INPUT / OUTPUT
/** Stampa il vettore v ben formattato [v1, v2, ..., vn] */
void print_vec(const double *v, size_t dim)
{
    size_t i;
    for (i = 0; i < dim; i++)
    {
        printf("%.3f ", v[i]);
    }
}

/** Stampa il vettore v INTERO ben formattato [vcount v2, ..., vn] */
// Ho aggiunto questa funzione perchè non tutte le funzioni di questa libreria lavorano con numeri float
void print_int_vec(const int *v, size_t dim)
{
    size_t i;
    for (i = 0; i < dim; i++)
    {
        printf("%d ", v[i]);
    }
}

/** Legge dim valori da stdin e li salva nel vettore v */
void scanf_vec(double *v, size_t dim)
{
    size_t i;
    double insert;
    for (i = 0; i < dim; i++)
    {
        printf("Insert %ld value: ", i);
        scanf("%lf", &insert);
        v[i] = insert;
    }
}

// OPERAZIONI ALGEBRICHE
/** res = v1 + v2 elemento per elemento*/
void add_vec(const double *v1, const double *v2, double *res, size_t dim)
{
    size_t i;
    for (i = 0; i < dim; i++)
    {
        res[i] = v1[i] + v2[i];
    }
}

/** res = v1 + k  per ogni elemento*/
void adds_vec(const double *v1, double k, double *res, size_t dim)
{
    size_t i;
    for (i = 0; i < dim; i++)
    {
        res[i] = v1[i] + k;
    }
}

/** res = v * k (moltiplicazione per scalare) */
void muls_vec(const double *v, double k, double *res, size_t dim)
{
    size_t i;
    for (i = 0; i < dim; i++)
    {
        res[i] = v[i] * k;
    }
}

/** res = v1 - v2 using the fact that v1-v2 = v1 + (-1) * v2 */
void sub_vec(const double *v1, const double *v2, double *res, size_t dim)
{
    size_t i;

    muls_vec(v2, -1.0, res, dim);
    for (i = 0; i < dim; i++)
    {
        res[i] += v1[i];
    }
}

/** Prodotto scalare (v1 • v2) */
double dot_vec(const double *v1, const double *v2, size_t dim)
{
    size_t i;
    double result;
    for (i = 0; i < dim; i++)
    {
        result += v1[i] * v2[i];
    }
    return result;
}

// MANIPOLAZIONE VETTORI
/** Concatena v1 (dim1) e v2 (dim2) in res (dim1 + dim2 elementi) */
void concat_vec(const double *v1, size_t dim1, const double *v2, size_t dim2, double *res)
{
    size_t i;
    // Add values from array1
    for (i = 0; i < dim1; i++)
    {
        res[i] = v1[i];
    }
    // Add values from array2
    for (i = 0; i < dim2; i++)
    {
        res[dim1 + i] = v2[i];
    }
}

/** Inverte l'ordine degli elementi (es. [1,2,3] → [3,2,1]) */
void reverse_vec(double *v, size_t dim)
{
    size_t i;
    double temp;
    for (i = 0; i < dim / 2; i++)
    {
        temp = v[i];
        v[i] = v[dim - 1 - i];
        v[dim - 1 - i] = temp;
    }
}

/** Ordina gli elementi in ordine crescente */
void sort_vec(double *v, size_t dim)
{
    for (size_t i = 0; i < dim - 1; i++)
    {
        for (size_t j = 0; j < dim - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                // Swap between elements
                double temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

/** Mescola gli elementi in modo casuale */
void shuffle_vec(double *v, size_t dim)
{
    srand(time(NULL));
    int i, random1, random2;
    double r1, r2;
    for (i = 0; i < dim / 2; i++)
    {
        random1 = rand() % dim;
        random2 = rand() % dim;
        r1 = v[random1];
        v[random1] = v[random2];
        v[random2] = r1;
    }
}

/** Shift a destra*/
void rshft_vec(double *v, size_t step, size_t dim)
{
    if (step > dim)
    {
        return;
    }
    // Create temporary storage for the elements that will be wrapped around
    double temp[step];
    for (size_t i = 0; i < step; i++)
    {
        temp[i] = v[dim - step + i];
    }

    // Shift elements to the right
    for (size_t i = dim - 1; i >= step; i--)
    {
        v[i] = v[i - step];
    }

    // Copy the wrapped elements to the beginning
    for (size_t i = 0; i < step; i++)
    {
        v[i] = temp[i];
    }
}

/** Shift a sinistra*/
void lshft_vec(double *v, size_t step, size_t dim)
{
    if (step > dim)
    {
        return;
    }

    // Create temporary storage for the elements that will be wrapped around
    double temp[step];
    for (size_t i = 0; i < step; i++)
    {
        temp[i] = v[i];
    }

    // Shift elements to the left
    for (size_t i = 0; i < dim - step; i++)
    {
        v[i] = v[i + step];
    }

    // Copy the wrapped elements to the end
    for (size_t i = 0; i < step; i++)
    {
        v[dim - step + i] = temp[i];
    }
}

/** Rotate a destra: rispetto allo shift gli elementi che escono a destra rientrano in testa (sinistra)*/
void rrot_vec(double *v, size_t step, size_t dim)
{
    printf("Function not implemented yet...");
    return;
}

/** Rotate a sinistra: rispetto allo shift gli elementi che escono a sinistra rientrano in coda (destra)*/
void lrot_vec(double *v, size_t step, size_t dim)
{
    printf("Function not implemented yet...");
    return;
}

/** Copia n elementi da src a dest (n <= dim) */
void slice_vec(const double *src, double *dest, int start, int n, size_t dim)
{
    // Come devo copiare gli elementi?
    // Devono essere appendati alla fine o copiati nello stesso ordine come inserito da user?
    // Come risolvo le incongruenze di dimensione tra gli array?
}

// —— Inizializzazione ——
/** Riempie il vettore con valori casuali in [min, max] */
// INT? non è compatibile con il resto della libreria
void rand_vec(int *v, size_t dim, int min, int max)
{
    size_t i;
    int random;
    for (i = 0; i < dim; i++)
    {
        random = rand() % max + min;
        v[i] = random;
    }
}

/** Riempie il vettore con val */
void fill_vec(double *v, size_t dim, double val)
{
    size_t i;
    for (i = 0; i < dim; i++)
    {
        v[i] = val;
    }
}

/** Azzera il vettore */
void zero_vec(double *v, size_t dim)
{
    size_t i;
    for (i = 0; i < dim; i++)
    {
        v[i] = 0;
    }
}

// —— Norme e geometria ——
/** Restituisce ||v|| il modulo (norma euclidea) */
double norm_vec(const double *v, size_t dim){
    printf("Function not implemented yet");
}

// —— Statistiche e utilità ——
/** Restituisce la media degli elementi */
double mean_vec(const double *v, size_t dim) {
    size_t i;
    double sum;
    for (i = 0; i < dim; i++)
    {
        sum += v[i];
    }
    return sum / dim;   
}

/** Restituisce il valore minimo */
double min_vec(const double *v, size_t dim) {
    size_t i;
    double min_val = v[0];
    for (i = 0; i < dim; i++)
    {
        if (v[i] < min_val)
        {
            min_val = v[i];
        }
    }
    return min_val;
}

/** Restituisce il valore massimo */
double max_vec(const double *v, size_t dim) {
    size_t i;
    double max_val = v[0];
    for (i = 0; i < dim; i++)
    {
        if (v[i] > max_val)
        {
            max_val = v[i];
        }
    }
    return max_val;
}

/** Somma di tutti gli elementi */
double sum_vec(const double *v, size_t dim) {
    size_t i;
    double total = 0;
    for (i = 0; i < dim; i++)
    {
        total += v[i];
    }
    return total;
}

/** Confronta due vettori con tolleranza tol. Restituisce true se |v1_i - v2_i| < tol per tutti gli elementi */
bool eq_vec(const double *v1, const double *v2, size_t dim, double tol) {
    printf("Function not implemented yet");
}

/** Applica func a ogni elemento (modifica v direttamente) */
void map_vec(double *v, size_t dim, double (*func)(double)) {
    printf("Function not implemented yet");
}

#include "vectLib.h"

// INPUT / OUTPUT
/** Stampa il vettore v ben formattato [v1, v2, ..., vn] */
void print_vec(const double *v, size_t dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("%.3f ", v[i]);
    }
}

/** Legge dim valori da stdin e li salva nel vettore v */
void scanf_vec(double *v, size_t dim)
{
    int i;
    double insert;
    for (i = 0; i < dim; i++)
    {
        printf("Insert %d value: ", i);
        scanf("%lf", &insert);
        v[i] = insert;
    }
}

// OPERAZIONI ALGEBRICHE
/** res = v1 + v2 elemento per elemento*/
void add_vec(const double *v1, const double *v2, double *res, size_t dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        res[i] = v1[i] + v2[i];
    }
}

/** res = v1 + k  per ogni elemento*/
void adds_vec(const double *v1, double k, double *res, size_t dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        res[i] = v1[i] + k;
    }
}

/** res = v * k (moltiplicazione per scalare) */
void muls_vec(const double *v, double k, double *res, size_t dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        res[i] = v[i] * k;
    }
}

/** res = v1 - v2 using the fact that v1-v2 = v1 + (-1) * v2 */
void sub_vec(const double *v1, const double *v2, double *res, size_t dim)
{
    int i;

    muls_vec(v2, -1.0, res, dim);
    for (i = 0; i < dim; i++)
    {
        res[i] += v1[i];
    }
}

/** Prodotto scalare (v1 • v2) */
double dot_vec(const double *v1, const double *v2, size_t dim)
{
    int i;
    double result;
    for ( i = 0; i < dim; i++)
    {
        result += v1[i] * v2[i];
    }
    return result;
}

// MANIPOLAZIONE VETTORI
/** Concatena v1 (dim1) e v2 (dim2) in res (dim1 + dim2 elementi) */
void concat_vec(const double *v1, size_t dim1, const double *v2, size_t dim2, double *res) {
    int i;
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
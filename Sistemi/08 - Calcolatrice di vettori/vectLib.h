#ifndef VECTLIB_H
#define VECTLIB_H

#include <stdio.h>
#include <stdbool.h>

// —— Input/Output ——
/** Stampa il vettore v ben formattato [v1, v2, ..., vn] */
void print_vec(const double *v, size_t dim);

/** Legge dim valori da stdin e li salva nel vettore v */
void scanf_vec(double *v, size_t dim);

// —— Operazioni algebriche ——
/** res = v1 + v2 elemento per elemento*/
void add_vec(const double *v1, const double *v2, double *res, size_t dim);

/** res = v1 + k  per ogni elemento*/
void adds_vec(const double *v1, double k, double *res, size_t dim);

/** res = v * k (moltiplicazione per scalare) */
void muls_vec(const double *v, double k, double *res, size_t dim);

/** res = v1 - v2 ...sfruttare muls_vec() */
void sub_vec(const double *v1, const double *v2, double *res, size_t dim);

/** Prodotto scalare (v1 • v2) */
double dot_vec(const double *v1, const double *v2, size_t dim);

// —— Manipolazione vettori ——
/** Concatena v1 (dim1) e v2 (dim2) in res (dim1 + dim2 elementi) */
void concat_vec(const double *v1, size_t dim1, const double *v2, size_t dim2, double *res);

/** Inverte l'ordine degli elementi (es. [1,2,3] → [3,2,1]) */
void reverse_vec(double *v, size_t dim);

/** Ordina gli elementi in ordine crescente */
void sort_vec(double *v, size_t dim);

/** Mescola gli elementi in modo casuale */
void shuffle_vec(double *v, size_t dim);

/** Shift a destra*/
void rshft_vec(double *v, size_t step, size_t dim);
/** Shift a sinistra*/
void lshft_vec(double *v, size_t step, size_t dim);

/** Rotate a destra: rispetto allo shift gli elementi che escono a destra rientrano in testa (sinistra)*/
void rrot_vec(double *v, size_t step, size_t dim);
/** Rotate a sinistra: rispetto allo shift gli elementi che escono a sinistra rientrano in coda (destra)*/
void lrot_vec(double *v, size_t step, size_t dim);

/** Copia n elementi da src a dest (n <= dim) */
void slice_vec(const double *src, double *dest, int start, int n);

// —— Inizializzazione ——
/** Riempie il vettore con valori casuali in [min, max] */
void rand_vec(int *v, size_t dim, int min, int max);

/** Riempie il vettore con val */
void fill_vec(double *v, size_t dim, double val);

/** Azzera il vettore */
void zero_vec(double *v, size_t dim);

// —— Norme e geometria ——
/** Restituisce ||v|| il modulo (norma euclidea) */
double norm_vec(const double *v, size_t dim);

// —— Statistiche e utilità ——
/** Restituisce la media degli elementi */
double mean_vec(const double *v, size_t dim);

/** Restituisce il valore minimo */
double min_vec(const double *v, size_t dim);

/** Restituisce il valore massimo */
double max_vec(const double *v, size_t dim);

/** Somma di tutti gli elementi */
double sum_vec(const double *v, size_t dim);

/** Confronta due vettori con tolleranza tol. Restituisce true se |v1_i - v2_i| < tol per tutti gli elementi */
bool eq_vec(const double *v1, const double *v2, size_t dim, double tol);

/** Applica func a ogni elemento (modifica v direttamente) */
void map_vec(double *v, size_t dim, double (*func)(double));

#endif /* VECTLIB_H */
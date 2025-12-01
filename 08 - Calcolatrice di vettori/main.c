#include "vectlib.h"
#define DIM 10

int main()
{
    double v1[DIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double v2[3] = {4, 5, 6};
    int v3[DIM];

    rand_vec(v3, DIM, 1, 10);
    print_int_vec(v3, DIM);
}


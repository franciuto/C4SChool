#include <stdio.h>

int main()
{
    float raggio, area, circonferenza;

    printf("Inserire raggio del cerchio: ");
    scanf("%f" ,&raggio);

    area = raggio * 3.14;
    circonferenza = raggio * 2 * 3.14;

    printf("L'area del cerchio e' %.2f mentre la sua circonferenza e' %.2f" ,area,circonferenza );


}
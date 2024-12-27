#include <stdio.h>

int main()
{
    float raggio, area, circonferenza;
    const float PI = 3.1415;

    printf("Inserire raggio del cerchio: ");
    scanf("%f" ,&raggio);

    area = raggio * 3.14;
    circonferenza = raggio * 2 * PI;

    printf("L'area del cerchio e' %.2f mentre la sua circonferenza e' %.2f" ,area,circonferenza);
    system("pause");
    return 0;
}
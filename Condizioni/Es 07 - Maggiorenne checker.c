// Visualizzare data l'età di un ragazzo se è maggiorenne oppure no
#include <stdio.h>

int main() {
  int età;

  printf("Inserire l'eta': ");
  scanf("%d", &età);

  if (età >= 18) {
    printf("Sei maggiorenne!!");
  } else {
    printf("Sei minorenne!!");
  }
}

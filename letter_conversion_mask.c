#include <stdio.h>

/* CHAR CONVERSION */
int main()
{
  char usr_input[150] = {'\0'};
  char result[150] = {'\0'};
  char choice;

  printf("** Char conversion **\n1) lowercase to UPPERCASE\n2) UPPERCASE to lowercase\nChoose an option: ");
  scanf("%c", &choice);
  printf("\nInsert your string: ");
  scanf("%149s", usr_input);


  for (size_t i = 0; usr_input[i] != '\0'; i++)
  {
    if (choice == '1') {
      result[i] = usr_input[i] & '0b11011111'; // 0xDF
    } else if (choice == '2') {
      result[i] = usr_input[i] | 0b00100000; // 0x20
    }
    printf("%C" , result[i]);
  }
}
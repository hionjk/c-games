#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../headers/utils.h"

void clrBuffer() { while(getchar() != '\n'); }

void clrScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void scanNumber(int* num) {
  int scanRes;

  do {
    printf("Digite o número -> ");
    scanRes = scanf("%d", num);
    clrBuffer();
    if(scanRes == 0) {
      printf("Erro: Tem que escrever o numero!\n");
    }
   } while (scanRes == 0);
}

/*
  arr should ends in NULL
*/
int getStrArrLen(const char* arr[]) {
  int len = 0;

  while (arr[len] != NULL) {
    len++;
  }

  return len;
}

int getUsrOption(const char **options) {
  char usrOption[BUFSIZ];
  char format[20];
  int i, res;
  int optionsLen;

  optionsLen = getStrArrLen(options);

  printf("\nDigite sua escolha -> ");
  snprintf(format, sizeof(format), "%%%lus", sizeof(usrOption) - 1);

  scanf(format, usrOption);
  clrBuffer();

  for (int i = 0; usrOption[i] != '\0'; i++) {
    usrOption[i] = tolower(usrOption[i]);
  }
  
  for(i = 0; i < optionsLen; i++) {
    
    res = strcmp(usrOption, options[i]);

    if(res == 0) {
      return i;
    }

  }

  printf("Erro: Este opeção não existe!\n\n");
  return USR_OPTION_ERR;
}
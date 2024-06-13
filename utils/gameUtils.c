#include <stdio.h>
#include <stdlib.h>
#include "../headers/utils.h"

void printGameTitle(const char* name, const char* object) {
  printf("|-------%s-------\n", name);
  printf("|Objeto: %s\n", object);
  printf("|------------------------------\n");
  putchar('\n');
}

void printGameStatus(int currentPnts, int winPnts, int lifePnts) {
  int i;
  printf("Vidas (%d):", lifePnts);
  for(i = 0; i < lifePnts; i++) 
    printf(" 0");

  putchar('\n');
  if(winPnts > 1) {
    printf("Pontuação: %d/%d\n", currentPnts, winPnts);
  }
  putchar('\n');

}

int checkGameEnd(int currentPnts, int winPnts, int lifePnts) {
  if(currentPnts >= winPnts) {
    clrScreen();
    printf("|-----------Game end----------|\n");
    printf("|  *           *         *    |\n");
    printf("|   Parabens! Voce ganhou :)  |\n");
    printf("|        *           *      * |\n");
    printf("|-----------------------------|\n\n");
    return 1;
  }

  if(lifePnts <= 0) {
    clrScreen();
    printf("|-------------------Game end-------------------|\n");
    printf("|  :(           :(                       :(    |\n");
    printf("|  Os pontos de vida acabaram, você perdeu :(  |\n");
    printf("|         :(            :(          :(         |\n");
    printf("|----------------------------------------------|\n\n");
    return -1;
  }

  return 0;
}

int randNum(int min, int max) {
  return ((rand() % (max - min)) + min + 1);
}
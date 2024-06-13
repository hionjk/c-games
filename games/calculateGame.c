#include <stdio.h>

#include "../headers/utils.h"
#include "../headers/gameUtils.h"

#define TITLE "Jogo de calculos"
#define OBJECT "Neste jogo você precisa inserir o resultado correto de uma expressão."

#define START_LIFE_POINTS 10
#define POINTS_TO_WIN 1

#define MAX_NUMBER 15
#define MIN_NUMBER 2

void calculateGame() {
  int a, b;

  int correctRes;
  int userRes;

  int opNum;
  char op;

  int lifePnts = 3;
  int currentPnts = 0;
  int winPnts = 3;

  printGameTitle(TITLE, OBJECT);

  for(;;) {

    printGameStatus(currentPnts, winPnts, lifePnts);
    a = randNum(MIN_NUMBER, MAX_NUMBER);
    b = randNum(MIN_NUMBER, MAX_NUMBER);

    opNum = (a != 0 && b != 0) && (a % b == 0) ? randNum(0, 3) : randNum(0, 2);

    if(opNum == 0) {
      op = '*';
      correctRes = a * b;
    } else if(opNum == 1) {
      op = '+';
      correctRes = a + b;
    } else if(opNum == 2) {
      op = '-';
      correctRes = a - b;
    } else if(opNum == 3) {
      op = '/';
      correctRes = a / b;
    }

    printf("%d %c %d = ?\n", a, op, b);
    
    scanNumber(&userRes);
    
    clrScreen();
    printGameTitle(TITLE, OBJECT);

    if(userRes == correctRes) {
      printf("Certo! -> %d\n\n", correctRes);
      currentPnts++;
    } else {
      printf("Errado! Resposta correta -> %d\n\n", correctRes);
      lifePnts--;
    }

    int res;
    res = checkGameEnd(currentPnts, winPnts, lifePnts);
    if(res != 0) {
      return;
    }
  }
}
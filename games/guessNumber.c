#include <stdio.h>

#include "../headers/utils.h"
#include "../headers/gameUtils.h"

#define TITLE "Adivinhe o número"
#define OBJECT "Combine o número para ganhar"

#define START_LIFE_POINTS 8
#define POINTS_TO_WIN 1

#define START_MAX_NUMBER 100
#define START_MIN_NUMBER 1

void guessNumberGame() {

  int lifePnts = START_LIFE_POINTS;
  int winPnts = POINTS_TO_WIN;
  int currentPnts = 0;
  
  int num;
  int usrNum;

  int maxNum = START_MAX_NUMBER;
  int minNum = START_MIN_NUMBER;

  num = randNum(minNum, maxNum);

  printGameTitle(TITLE, OBJECT);

  for(;;) {
    printGameStatus(currentPnts, winPnts, lifePnts);
    printf("O número oculto está entre %d e %d.\n", minNum, maxNum);

    scanNumber(&usrNum);

    clrScreen();
    printGameTitle(TITLE, OBJECT);

    if(usrNum < num) {
      printf("INFO: O número oculto é mais do que %d\n\n", usrNum);
      if(usrNum > minNum) {
        minNum = usrNum;
      }  
      lifePnts--;
    } else if(usrNum > num) {
      printf("INFO: O número oculto é menos do que %d\n\n", usrNum);
      if(usrNum < maxNum) {
        maxNum = usrNum;
      } 
      lifePnts--;
    } else {
      currentPnts++;
    }

    int res;
    res = checkGameEnd(currentPnts, winPnts, lifePnts);
    if(res == 1) {
      printf("O número oculto foi %d\n", num);
      return;
    } else if (res == -1) {
      printf("O número oculto foi %d\n", num);
      return;
    }

  }
}
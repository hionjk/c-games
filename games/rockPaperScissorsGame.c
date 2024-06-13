#include <stdio.h>

#include "../headers/gameUtils.h"
#include "../headers/utils.h"

#define TITLE "Pedra Papel Tesoura"
#define OBJECT "Derrote o computador com uma tesoura de pedra e papel 3 vezes."

#define START_LIFE_POINTS 5
#define POINTS_TO_WIN 3

enum hand {rock, paper, scissor};

void printResult(enum hand usrHand, enum hand cHand, char* res) {
  const char* handNames[] = {"pedra", "papel", "tesoura"};

  printf("Computer: %s\nVocê: %s\n%s\n\n", handNames[cHand], handNames[usrHand], res);
}

void rockPaperScissorsGame() {

  /* 
    uHand - User Hand 
    cHand - Computer Hand
  */

  enum hand uHand, cHand;

  const char* options[] = {"pedra", "papel", "tesoura", 
  "1", "2", "3", NULL};

  int lifePnts = START_LIFE_POINTS;
  int winPnts = POINTS_TO_WIN;
  int currentPnts = 0;

  int res;

  printGameTitle(TITLE, OBJECT);

  for(;;) {
    printGameStatus(currentPnts, winPnts, lifePnts);
    
    printf("|-------------|\n");
    printf("| 1 - pedra   |\n");
    printf("| 2 - papel   |\n");
    printf("| 3 - tesoura |\n");
    printf("|-------------|\n");
    res = getUsrOption(options);
    
    clrScreen(); 
    printGameTitle(TITLE, OBJECT);

    if(res == USR_OPTION_ERR) {
      printf("Erro: Tem que escrever: pedra, papel ou tesoura!\n\n");
      continue;
    } else {
      if(res >= 3) {
        res -= 3;
      }
      uHand = res;
    }

    cHand = randNum(0, 2);

    clrScreen();
    printGameTitle(TITLE, OBJECT);
    
    if((uHand == rock && cHand == scissor) ||
    (uHand == scissor && cHand == paper) ||
    (uHand == paper && cHand == rock)) 
    {
      currentPnts++;
      printResult(uHand, cHand, "Voce ganhou!");
    }
    else if ((cHand == rock && uHand == scissor) ||
    (cHand == scissor && uHand == paper) ||
    (cHand == paper && uHand == rock)) 
    {
      printResult(uHand, cHand, "Voce perdeu");
      lifePnts--;
    } else {
      printf("Você e o computador escolheram a mesma coisa.\nNinguém ganhou.\n\n");
    }

    int res;
    res = checkGameEnd(currentPnts, winPnts, lifePnts);

    if(res != 0) {
      return;
    }
  }

  return;
}
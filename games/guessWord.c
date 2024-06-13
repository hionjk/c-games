#include <stdio.h>
#include <string.h>

#include "../headers/utils.h"
#include "../headers/gameUtils.h"

#define TITLE "Adivinhe a palavra"
#define OBJECT "Adivinhe a palavra para ganhar o jogo!"

#define START_LIFE 10

void guessWordGame() {
  const char* words[] = {
      "cachorro",
      "gato",
      "elefante",
      "girafa",
      "tigre",
      "rinoceronte",
      "macaco",
      "cavalo",
      "urso",
      "zebra",
      "panda",
      "golfinho",
      "pinguim",
      "crocodilo",
      "leopardo",
      "camelo",
      "canguru",
      NULL
    };


  int lifePnts = START_LIFE;
  int currentPnts = 0;

  char usrChar;

  int i;
  int prevPnts;

  int wordsLen = getStrArrLen(words);
  int randWordIndex = randNum(0, wordsLen - 1);
  char randWord[50];

  strcpy(randWord, words[randWordIndex]);

  int randWordLen = strlen(randWord);
  int winPnts = randWordLen;

  char guessStatus[randWordLen];

  for(i = 0; i < randWordLen; i++) {
    guessStatus[i] = '_';
  } 

  for(;;) {
    printGameTitle(TITLE, OBJECT);
    printGameStatus(currentPnts, winPnts, lifePnts);

    for(i = 0; i < randWordLen; i++) {
      printf("%c, ", guessStatus[i]);
    }

    putchar('\n');

    printf("\nEscreve a letra -> ");
    scanf("%c", &usrChar);
    clrBuffer();

    prevPnts = currentPnts;

    for(i = 0; i < randWordLen; i++) {
      if(randWord[i] == usrChar && guessStatus[i] == '_') {
        guessStatus[i] = usrChar;
        currentPnts++;
      }
    }

    if(prevPnts == currentPnts) {
      lifePnts--;
    }

    int res;
    res = checkGameEnd(currentPnts, winPnts, lifePnts);

    if(res == 1) {
      printf("Parabens! A palavra foi '%s'\n", randWord);
      return;
    }
    else if(res == -1) {
      printf("A palavra foi '%s'\n", randWord);
      return;
    }

    clrScreen();
  }

  return;
}
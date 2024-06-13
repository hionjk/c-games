#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#include "headers/games.h"
#include "headers/utils.h"

#define ASK_RESTART 1
#define ASK_EXIT 2
#define ASK_MENU 3

void printMenu(char[]);
void startGame(int num);
void getTimeGreeting(char *);

int askToContinue();

enum jogos_enum {Calculate, GuessNumber, RockPaperScissors, GuessWord};

int main(int argc, char **argv) {
  srand(time(NULL));
  setlocale(LC_ALL, "Portuguese");

  char usrName[18];
  char timeGreeting[20];

  int option;
  int asking;

  getTimeGreeting(timeGreeting);
  
  printf("%s Escreve o seu nome (1-15) > ", timeGreeting);
  scanf("%17s", usrName);

  clrBuffer();
  clrScreen();

  while(1) {
    printMenu(usrName);

    const char* menuOptions[] = {"1", "2", "3", "4",
  "s", "sair", NULL};

    option = getUsrOption(menuOptions);

    if(option == USR_OPTION_ERR) {
      clrScreen();
      printf("Erro: Este opeção não existe!\n\n");
      continue;
    }

    switch(option) {
      case Calculate:
      case GuessNumber:
      case GuessWord:
      case RockPaperScissors:
        clrScreen();
        startGame(option);
        asking = askToContinue();

        if(asking == ASK_RESTART) {
          while(asking == ASK_RESTART) {
            clrScreen();
            startGame(option);
            asking = askToContinue();
          }
        }

        if(asking == ASK_EXIT) {
          return 0;
        }
      
        break;
      default:
        return 0;
    }

     clrScreen();
  }

	return 0;
}

void startGame(int number) {
  switch(number) {
    case Calculate:
      calculateGame();
      return;
    case GuessNumber:
      guessNumberGame();
      return;
    case RockPaperScissors:
      rockPaperScissorsGame();
      return;
    case GuessWord:
      guessWordGame();
      return;
  }
}

void printMenu(char usrName[]) {
    printf("|--------MENU DO JOGO-------|\n");
    printf("| Jogo de %-17s |\n", usrName);
    printf("|                           |\n");
    printf("| 1 - Cálculos              |\n");
    printf("| 2 - Adivinhe o número     |\n");
    printf("| 3 - Pedra Papel Tesoura   |\n");
    printf("| 4 - Adivinhe a palavra    |\n");
    printf("|                           |\n");
    printf("| S - Sair                  |\n");
    printf("|---------------------------|\n");
}

int askToContinue() {
  const char* options[] = {"1", "2", "s", "sair", NULL};
  int option;

  while(1) {
    putchar('\n');
    printf("|-------MENU FINAL-------|\n");
    printf("| 1 - Jogar novamente    |\n");
    printf("| 2 - Voltar ao menu     |\n");
    printf("| S - Sair               |\n");
    printf("|------------------------|\n");
    
    option = getUsrOption(options);

    if(option == USR_OPTION_ERR) {
      continue;
    }

    switch (option) {
      case 0:
        return ASK_RESTART;
      case 1:
        return ASK_MENU;
      case 2:
      case 3:
        return ASK_EXIT;
    }
  }
}

void getTimeGreeting(char str[]) {
  struct tm *localTime;
  time_t curTime;
  int hour;
  
  time(&curTime);

  localTime = localtime(&curTime);

  hour = localTime->tm_hour;
  
  if(hour >= 6 && hour < 12) {
    strcpy(str, "Bom dia!");
  } else if(hour >= 12 && hour < 19) {
    strcpy(str, "Boa tarde!");
  } else {
    strcpy(str, "Boa noite!");
  }
}
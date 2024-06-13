
#ifndef GAME_UTILS_H
#define GAME_UTILS_H

void printGameTitle(const char* title, const char* object);

/*
  Return: 
      1 -> win; 
      -1 -> loose; 
      0 -> not end yet
*/
int checkGameEnd(int currentPnts, int winPnts, int lifePnts);
void printGameStatus(int currentPnts, int winPnts, int lifePnts);

int randNum(int, int);

#endif
#ifndef UTILS_H
#define UTILS_H

#define USR_OPTION_ERR -1

void clrBuffer();
void clrScreen();

/*
  Return index of choosed option.
*/
int getUsrOption(const char* options[]);

int getStrArrLen(const char*[]);

void scanNumber(int*);

#endif
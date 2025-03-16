#ifndef MENU_H
#define MENU_H
#define SMAX 50

int menu(void);
void titlePrint(char *title);
int selec(char title[], int optNum, char optName[][SMAX]);

#endif

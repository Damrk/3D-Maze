#include "menu.h"
#include "mazemove.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>


int menu(void)
{
    char title[] = " _____ ______   ________  ________  _______        "
                   "   ________  ________\n|\\   _ \\  _   \\|\\   __  "
                   "\\|\\_____  \\|\\  ___ \\         |\\_____  \\|\\  "
                   " ___ \\\n\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\\\|_"
                   "__/  /\\ \\   __/|        \\|____|\\ /\\ \\  \\_|\\"
                   " \\\n \\ \\  \\\\|__| \\  \\ \\   __  \\   /  / /\\"
                   " \\  \\_|/__            \\|\\  \\ \\  \\ \\\\ \\\n "
                   " \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ /  /_/__\\ \\"
                   "  \\_|\\ \\          __\\_\\  \\ \\  \\_\\\\ \\\n  "
                   " \\ \\__\\    \\ \\__\\ \\__\\ \\__\\\\________\\ "
                   "\\_______\\        |\\_______\\ \\_______\\\n    \\"
                   "|__|     \\|__|\\|__|\\|__|\\|_______|\\|_______|  "
                   "      \\|_______|\\|_______|\n";
    char option[][SMAX] = {"Play", "Options", "Exit"};
    return selec(title,3,option);
}

void titlePrint(char *title)
{
    printf("%s", title);
}

int selec(char title[], int optNum, char optName[][SMAX])
{
    char arrow[optNum];
    arrow[0] = '>';
    for(int i = 1; i < optNum; i++)
    {
        arrow[i] = ' ';
    }
    
    _Bool valid = 1;
    int input;
    int key;
    char temp;
    int search = 0;
    while(valid)
    {
        system("cls");
        titlePrint(title);
        for(int i = 0; i < optNum; i++)
        {
            printf("%c %s\n", arrow[i], optName[i]);
        }
        input = getch();
        if(input == 224)
        {
            key = getch();
            switch(key)
            {
                case UP:
                    temp = arrow[0];
                    for(int i = 0; i < optNum; i++)
                    {
                        arrow[i] = arrow[i+1];
                    }
                    arrow[optNum-1] = temp;
                    break;
                case DOWN:
                    temp = arrow[optNum-1];
                    for(int i = optNum - 1; i > 0; i--)
                    {
                        arrow[i] = arrow[i - 1];
                    }
                    arrow[0] = temp;
                    break;
                default:
                    break;
            }
        }
        else
        {
            if(input == 13)
            {
                while(arrow[search] != '>')
                {
                    search++;
                }
                valid = 0;
            }
        }
    }
    return search;;
}

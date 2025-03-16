/* *********************************************************************
* 3D-Maze
* An ASCII 3D Maze Game
* Version A
* *********************************************************************/

#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include "graphics.h"
#include "mazemove.h"
#include "menu.h"
#include "wincom.h"

int main(void)
{
    //windowSize();
    int map[][MSZ]= {{0,0,0,0,0,0,0,0,0,0},
                     {0,1,1,1,1,1,1,1,1,0},
                     {0,1,0,0,0,1,0,2,1,0},
                     {0,1,0,1,0,1,0,1,1,0},
                     {0,1,0,1,0,1,0,1,1,0},
                     {0,1,0,1,0,1,0,1,1,0},
                     {0,1,0,1,0,1,0,1,1,0},
                     {0,1,0,1,0,0,0,1,1,0},
                     {0,1,1,1,1,1,1,1,1,0},
                     {0,0,0,0,0,0,0,0,0,0}};
    struct MAZER advent = {2,7,north};
    char display[WID][HEI]; /* x - y */
    int i = 1;
    while(i != 2)
    {
        i = menu();
        switch(i)
        {
            case 0:
                PlaySound("ost\\m.wav",NULL,SND_ASYNC | SND_LOOP);
                border(display, WID, HEI);
                /* R1 R2 values */
                while(map[advent.y][advent.x] != 2)
                {
                    rendering(map, advent, display);
                    for(int y = advent.y-2; y <= advent.y; y++)
                    {
                        for(int x = advent.x-1; x <= advent.x+1; x++)
                        {
                            if(x == advent.x && y == advent.y)
                            {
                                printf("@");
                            }
                            else
                            {
                                if(map[y][x] == 1)
                                {
                                    printf("%c", BK);   
                                }
                                else
                                {
                                    printf(" ");    
                                }      
                            }
                        }
                        printf("\n");
                    }
                    printf("\n");
//                    for(int y = 0; y < MSZ; y++)
//                    {
//                        for(int x = 0; x < MSZ; x++)
//                        {
//                            if(x == advent.x && y == advent.y)
//                            {
//                                printf("@");
//                            }
//                            else
//                            {
//                                if(map[y][x] == 1)
//                                {
//                                    printf("%c", BK);   
//                                }
//                                else
//                                {
//                                    printf(" ");    
//                                }   
//                            }
//                        }
//                        printf("\n");
//                    }
                    printf("[%d,%d]\n", advent.x, advent.y);
                    advent = input(map, advent);
                }
                break;
            case 1:
                break;
            case 2:
                break;
            default:
                break;
        }
    }
    return 0;
}
